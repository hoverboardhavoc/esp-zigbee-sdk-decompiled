/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_check_in_context_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_check_in_context_init(undefined1 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = poll_control_srv_get_attr_desc(0xeff0);
  if (iVar1 != 0) {
    puVar2 = (undefined1 *)calloc(1,0x14);
    *puVar2 = param_1;
    *(undefined1 **)(iVar1 + 8) = puVar2;
    milli_timer_init(puVar2 + 4,poll_control_check_in_timeout,puVar2);
  }
  return;
}

