/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_parent_annce_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char zdo_parent_annce_handler(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  char cStack_2d;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_24;
  ushort auStack_22 [5];
  
  auStack_22[0] = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  if (param_1 == 0) {
    cVar5 = -2;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    cVar5 = -2;
  }
  else {
    iVar2 = nwk_is_device_zed();
    if (iVar2 == 0) {
      uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x14));
      af_read_le8(*(undefined4 *)(param_1 + 0x14),auStack_22,&uStack_2c);
      if (uVar3 < auStack_22[0]) {
        cVar5 = -2;
      }
      else {
        if ((0xfff7 < *(ushort *)(param_1 + 2)) &&
           (iVar2 = core_globals_get(), *(char *)(iVar2 + 0x16) != '\0')) {
          uVar3 = random_noncrypto_range_u32(0,0x2711);
          iVar2 = core_globals_get();
          *(char *)(iVar2 + 0x16) = (char)(uVar3 / 1000) + '\n';
        }
        cStack_2d = '\0';
        zmsg_append_bytes(*(undefined4 *)(param_2 + 0x14),1,&cStack_2d);
        cVar5 = '\0';
        for (uVar3 = 0; uVar3 < (uStack_2c & 0xff); uVar3 = uVar3 + 1 & 0xff) {
          iVar2 = (int)&uStack_2c + 1;
          af_read_bytes(*(undefined4 *)(param_1 + 0x14),auStack_22,8,iVar2);
          iVar4 = nwk_neighbor_table_get_by_extended(iVar2);
          if (((iVar4 != 0) && ((*(uint *)(iVar4 + 0xc) & 3) == 2)) &&
             (*(int *)(iVar4 + 0x14) << 7 < 0)) {
            cVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x14),8,iVar2);
            if (cVar1 != '\0') {
              return cVar1;
            }
            cVar5 = cVar5 + '\x01';
          }
        }
        if (cVar5 == '\0') {
          cVar5 = -2;
        }
        else {
          cStack_2d = cVar5;
          zmsg_write_bytes(*(undefined4 *)(param_2 + 0x14),0,1,&cStack_2d);
          cVar5 = '\0';
        }
      }
    }
    else {
      cVar5 = -2;
    }
  }
  return cVar5;
}

