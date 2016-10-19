void loop() {
    static enum {MOVING_CW, MOVING_CCW, STOPPED_CW, STOPPED_CCW} state;
    static unsigned long time_stopped;
    unsigned long now = millis();

    switch (state) {
    case MOVING_CW:
        if (digitalRead(LM2) == LOW) {  // hit switch
            digitalWrite(CW, LOW);      // stop
            state = STOPPED_CW;
            time_stopped = now;
        }
        break;
    case MOVING_CCW:
        if (digitalRead(LM1) == LOW) {  // hit switch
            digitalWrite(CCW, LOW);     // stop
            state = STOPPED_CCW;
            time_stopped = now;
        }
        break;
    case STOPPED_CW:
        if (now - time_stopped >= 5000) {
            digitalWrite(CCW, HIGH);    // restart
            state = MOVING_CCW;
        }
        break;
    case STOPPED_CCW:
        if (now - time_stopped >= 5000) {
            digitalWrite(CW, HIGH);     // restart
            state = MOVING_CW;
        }
        break;
    }
}
