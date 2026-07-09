/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_leave_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_leave_request(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_1 == (int *)0x0) {
    uVar3 = 2;
  }
  else {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xac0) == '\0') {
      iVar1 = nwk_is_joined();
      if (iVar1 == 0) {
        uVar3 = 0x2c2;
      }
      else {
        if (*param_1 != 0 || param_1[1] != 0) {
          piVar2 = (int *)nwk_get_extended_address();
          if ((*param_1 != *piVar2) || (param_1[1] != piVar2[1])) {
            iVar1 = nwk_is_device_zczr();
            if (iVar1 == 0) {
              return 0x2c8;
            }
            iVar1 = nwk_neighbor_table_get_by_extended(param_1);
            if (iVar1 == 0) {
              return 0x2c8;
            }
            if ((*(uint *)(iVar1 + 0xc) & 3) != 2) {
              return 0x2c8;
            }
            if ((*(uint *)(iVar1 + 0xc) & 0x3c0) != 0x140) {
              nwk_neighbor_get_shortaddr();
              nwk_send_leave(*(byte *)(param_1 + 2) & 1,*(byte *)(param_1 + 2) >> 1 & 1);
              return 0;
            }
            return 0x2c8;
          }
        }
        nwk_do_leave(0,*(byte *)(param_1 + 2) & 1,*(byte *)(param_1 + 2) >> 1 & 1);
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 3;
    }
  }
  return uVar3;
}

