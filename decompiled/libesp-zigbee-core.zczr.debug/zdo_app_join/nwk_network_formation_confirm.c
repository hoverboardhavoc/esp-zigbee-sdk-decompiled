/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> nwk_network_formation_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void nwk_network_formation_confirm(nwk_status_t status)

{
  _Bool _Var1;
  undefined3 in_register_00002029;
  undefined4 uVar2;
  uint8_t *key;
  undefined3 extraout_var;
  int iVar3;
  
  if (CONCAT31(in_register_00002029,status) == 0) {
    uVar2 = nwk_secur_get_current_key_seq();
    key = (uint8_t *)nwk_secur_get_key_by_seq();
    _Var1 = secur_is_key_valid(key);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      nwk_secur_set_key(0);
      uVar2 = 0;
    }
    iVar3 = nwk_secur_switch_key(uVar2);
    if (iVar3 != 0) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_join.c",0x1c3,
                    "nwk_network_formation_confirm","(nwk_secur_switch_key(key_seq)) == 0");
      if (&stack0x00000000 == (undefined1 *)0x10) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    zdo_comm_perform_next_op();
  }
  else {
    zdo_comm_signal_comm_done(CONCAT31(in_register_00002029,status) | 0x200);
  }
  return;
}

