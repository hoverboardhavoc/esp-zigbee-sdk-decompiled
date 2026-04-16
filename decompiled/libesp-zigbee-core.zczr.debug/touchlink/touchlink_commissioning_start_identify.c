/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_start_identify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_commissioning_start_identify(uint16_t duration)

{
  touchlink_commissioning_t *ptVar1;
  
  ptVar1 = touchlink_commissioning_get();
  if ((ptVar1->identify).cb != (touchlink_identify_callback_t)0x0) {
    ptVar1 = touchlink_commissioning_get();
    (ptVar1->identify).duration = duration;
    ptVar1 = touchlink_commissioning_get();
    (*(ptVar1->identify).cb)(duration);
    ptVar1 = touchlink_commissioning_get();
    milli_timer_stop(&(ptVar1->identify).timer);
    ptVar1 = touchlink_commissioning_get();
    milli_timer_init(&(ptVar1->identify).timer,touchlink_commissioning_identify_timeout,0);
    ptVar1 = touchlink_commissioning_get();
    milli_timer_start(&(ptVar1->identify).timer,1000);
  }
  return;
}

