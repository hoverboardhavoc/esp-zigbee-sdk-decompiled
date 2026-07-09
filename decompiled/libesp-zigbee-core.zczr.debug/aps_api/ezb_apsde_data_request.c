/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_api.o -> ezb_apsde_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_apsde_data_request(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar2 = 2;
  }
  else if ((param_1[6] == 0) && (*(short *)((int)param_1 + 0x16) != 0)) {
    iVar2 = 2;
  }
  else {
    iStack_2c = zmsg_alloc(0xc);
    if (iStack_2c == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = zmsg_append_bytes(*(undefined2 *)((int)param_1 + 0x16),param_1[6]);
      if (iVar2 == 0) {
        uStack_28 = *param_1;
        uStack_24 = param_1[1];
        uStack_20 = param_1[2];
        uStack_1c = param_1[3];
        uStack_18 = param_1[4];
        bVar1 = *(byte *)(param_1 + 5);
        uStack_14 = (bVar1 >> 5 & 1) << 4 |
                    bVar1 & 1 | (bVar1 >> 2 & 1) << 1 | (bVar1 >> 3 & 1) << 2 |
                    (bVar1 >> 4 & 1) << 3 | 0x20;
        iVar2 = aps_apsde_data_request(&iStack_2c);
      }
      else {
        zmsg_free(iStack_2c);
      }
    }
  }
  return iVar2;
}

