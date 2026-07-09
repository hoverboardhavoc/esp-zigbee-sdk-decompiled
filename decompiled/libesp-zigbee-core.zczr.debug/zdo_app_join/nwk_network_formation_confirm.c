/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> nwk_network_formation_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void nwk_network_formation_confirm(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = nwk_secur_get_current_key_seq();
    nwk_secur_get_key_by_seq();
    iVar2 = secur_is_key_valid();
    if (iVar2 == 0) {
      nwk_secur_set_key(0);
      uVar1 = 0;
    }
    iVar2 = nwk_secur_switch_key(uVar1);
    if (iVar2 != 0) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_join.c",0x1bc,
                    "nwk_network_formation_confirm","(nwk_secur_switch_key(key_seq)) == 0");
      if (&stack0x00000000 != (undefined1 *)0x10) {
        FUN_0001104e();
        return;
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    zdo_comm_perform_next_op();
  }
  else {
    zdo_comm_signal_comm_done(param_1 | 0x200);
  }
  return;
}

