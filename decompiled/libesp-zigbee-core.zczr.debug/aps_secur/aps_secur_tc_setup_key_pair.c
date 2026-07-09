/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_tc_setup_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_secur_tc_setup_key_pair(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  
  iVar2 = aps_secur_key_pair_is_ready_for_init_join();
  iVar3 = aps_secur_is_centralized();
  if (iVar3 == 0) {
    bVar4 = false;
  }
  else {
    iVar3 = core_globals_get();
    if ((*(ushort *)(iVar3 + 0x9bc) & 6) == 0) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
  }
  iVar3 = aps_secur_is_centralized();
  if (iVar3 == 0) {
    bVar5 = true;
  }
  else {
    iVar3 = core_globals_get();
    if ((*(ushort *)(iVar3 + 0x9bc) & 6) == 4) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
  }
  if (iVar2 == 0) {
    if ((bVar4) && (iVar3 = secur_ic_get_key(param_1,param_1 + 0x12), iVar3 == 0)) {
      aps_secur_key_pair_setup_ic_key_continue(param_1);
      return 0;
    }
    if (bVar5) {
      aps_secur_key_pair_setup_global_tclk(param_1);
      return 0;
    }
  }
  if (iVar2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

