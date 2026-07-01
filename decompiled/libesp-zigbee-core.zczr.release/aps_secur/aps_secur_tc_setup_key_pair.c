/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_tc_setup_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_secur_tc_setup_key_pair(aps_device_key_pair_t *key_pair)

{
  bool bVar1;
  bool bVar2;
  _Bool _Var3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar4;
  undefined3 extraout_var_01;
  int iVar5;
  
  iVar5 = 0;
  if (((key_pair->field_8).flags & 6) == 0) {
    _Var3 = secur_is_key_valid(key_pair->link_key);
    iVar5 = CONCAT31(extraout_var,_Var3);
  }
  _Var3 = aps_secur_is_centralized();
  bVar1 = false;
  if (CONCAT31(extraout_var_00,_Var3) != 0) {
    iVar4 = core_globals_get();
    bVar1 = (*(ushort *)(iVar4 + 0x9bc) & 6) != 0;
  }
  _Var3 = aps_secur_is_centralized();
  bVar2 = true;
  if (CONCAT31(extraout_var_01,_Var3) != 0) {
    iVar4 = core_globals_get();
    bVar2 = (*(ushort *)(iVar4 + 0x9bc) & 6) != 4;
  }
  if (iVar5 == 0) {
    if (bVar1) {
      iVar5 = secur_ic_get_key(key_pair);
      if (iVar5 == 0) {
        memcpy(key_pair->passphrase,key_pair->link_key,0x10);
        key_pair->incoming_frame_cntr = 0;
        key_pair->outgoing_frame_cntr = 0;
        *(byte *)&key_pair->field_8 = *(byte *)&key_pair->field_8 & 0x38 | 0x40;
        key_pair->timeout = 0xffff;
        return 0;
      }
    }
    if (!bVar2) {
      return -1;
    }
    aps_secur_key_pair_setup_global_tclk(key_pair);
  }
  return 0;
}

