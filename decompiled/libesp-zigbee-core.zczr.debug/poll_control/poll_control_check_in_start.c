/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_check_in_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_check_in_start(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)poll_control_check_in_context_get();
  if ((puVar1 != (undefined1 *)0x0) &&
     (iVar2 = poll_control_srv_get_attr_desc(*puVar1,0), iVar2 != 0)) {
    milli_timer_start(puVar1 + 4,**(int **)(iVar2 + 8) * 0xfa);
  }
  return;
}

