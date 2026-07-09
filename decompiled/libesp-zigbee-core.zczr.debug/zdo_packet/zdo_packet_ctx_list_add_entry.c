/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_ctx_list_add_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_packet_ctx_list_add_entry(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    uVar2 = 0x80;
  }
  else {
    if (*(char *)(param_1 + 0x18) != '\0') {
      uVar3 = nwk_pim_get_fast_poll_interval();
      nwk_pim_start_fast_poll(5000 / uVar3);
    }
    iVar1 = core_globals_get();
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar1 + 0xcac);
    *(int *)(iVar1 + 0xcac) = param_1 + 0x24;
    milli_timer_init(param_1 + 4,zdo_packet_ctx_entry_timeout,param_1);
    milli_timer_start(param_1 + 4,5000);
    uVar2 = 0;
  }
  return uVar2;
}

