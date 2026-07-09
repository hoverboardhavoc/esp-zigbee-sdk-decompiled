/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_api.o -> ezb_apsde_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_apsde_data_request(void *param_1)

{
  byte bVar1;
  int iVar2;
  int iStack_2c;
  undefined1 auStack_28 [10];
  undefined2 uStack_1e;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar2 = 2;
  if (param_1 != (void *)0x0) {
    if ((*(int *)((int)param_1 + 0x18) == 0) && (*(short *)((int)param_1 + 0x16) != 0)) {
      return 2;
    }
    iStack_2c = zmsg_alloc(0xc);
    iVar2 = 1;
    if (iStack_2c != 0) {
      iVar2 = zmsg_append_bytes(*(undefined2 *)((int)param_1 + 0x16),
                                *(undefined4 *)((int)param_1 + 0x18));
      if (iVar2 == 0) {
        uStack_14 = 0;
        memcpy(auStack_28,param_1,10);
        uStack_1e = *(undefined2 *)((int)param_1 + 10);
        bVar1 = *(byte *)((int)param_1 + 0x14);
        uStack_1c = *(undefined4 *)((int)param_1 + 0xc);
        uStack_18 = *(undefined4 *)((int)param_1 + 0x10);
        uStack_14 = CONCAT31(uStack_14._1_3_,
                             bVar1 >> 1 & 2 | bVar1 & 1 | 0x20 | bVar1 >> 1 & 4 | bVar1 >> 1 & 8 |
                             bVar1 >> 1 & 0x10 | (byte)uStack_14 & 0xc0);
        iVar2 = aps_apsde_data_request(&iStack_2c);
      }
      else {
        zmsg_free(iStack_2c);
      }
    }
  }
  return iVar2;
}

