/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_start_fast_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void poll_control_start_fast_poll(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = poll_control_srv_get_attr_desc(2);
  if (iVar2 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/poll_control.c",0x5b,
                  "poll_control_start_fast_poll","attr_desc");
  }
  else {
    uVar1 = (uint)**(ushort **)(iVar2 + 8) * 0xfa;
    if (uVar1 != 0) {
      nwk_pim_set_fast_poll_interval(uVar1);
      nwk_pim_start_fast_poll(param_1 / uVar1 & 0xffff);
      return;
    }
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/poll_control.c",0x5d,
                "poll_control_start_fast_poll","fast_poll_interval_ms > 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

