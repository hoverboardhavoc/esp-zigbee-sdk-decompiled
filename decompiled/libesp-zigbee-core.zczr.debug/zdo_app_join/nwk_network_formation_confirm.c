/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  uint8_t *key;
  undefined3 extraout_var;
  int iVar2;
  
  if (CONCAT31(in_register_00002029,status) == 0) {
    nwk_secur_get_current_key_seq();
    key = (uint8_t *)nwk_secur_get_key_by_seq();
    _Var1 = secur_is_key_valid(key);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      nwk_secur_set_key(0);
      iVar2 = nwk_secur_switch_key(0);
      if (iVar2 != 0) {
        __assert_func("//build/esp-zigbee/src/core/zdo/zdo_app_join.c",0x1c1,
                      "nwk_network_formation_confirm","(nwk_secur_switch_key(0)) == 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    zdo_comm_perform_next_op();
  }
  else {
    zdo_comm_signal_comm_done(CONCAT31(in_register_00002029,status) | 0x200);
  }
  return;
}

