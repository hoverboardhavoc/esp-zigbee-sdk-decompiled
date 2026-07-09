/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_intrp_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int af_intrp_data_request(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x14);
    iVar1 = aps_intrp_data_request();
    if (iVar1 == 0) {
      af_data_add_cnf_cb(iVar2,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
    }
    else if (iVar2 != 0) {
      zmsg_free(iVar2);
    }
  }
  return iVar1;
}

