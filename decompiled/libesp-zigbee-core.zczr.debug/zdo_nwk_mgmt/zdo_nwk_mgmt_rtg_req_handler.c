/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_rtg_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zdo_nwk_mgmt_rtg_req_handler(int param_1,int param_2)

{
  undefined4 uVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  uint __nmemb;
  uint uVar6;
  undefined2 *puVar7;
  undefined4 uStack_1c;
  void *pvStack_18;
  byte abStack_14 [4];
  
  abStack_14[0] = 0;
  uStack_1c = 0;
  pvStack_18 = (void *)0x0;
  if (((param_1 == 0) || (*(int *)(param_1 + 0x14) == 0)) || (param_2 == 0)) {
    uStack_1c = 0xfe;
  }
  else if (*(ushort *)(param_1 + 2) < 0xfff8) {
    iVar5 = zdo_op_nwk_mgmt_rtg_req(abStack_14,0);
    uStack_1c = CONCAT31(uStack_1c._1_3_,(char)iVar5);
    if (iVar5 == 0) {
      iVar5 = nwk_is_device_zczr();
      if (iVar5 == 0) {
        uStack_1c = CONCAT31(uStack_1c._1_3_,0x84);
      }
      else {
        __nmemb = zdo_nwk_mgmt_rtg_get_entries_capacity();
        uVar6 = zdo_nwk_mgmt_rtg_get_entries_num();
        if (uVar6 < 0xff) {
          uVar3 = zdo_nwk_mgmt_rtg_get_entries_num();
        }
        else {
          uVar3 = 0xff;
        }
        uVar1 = uStack_1c;
        uStack_1c._3_1_ = SUB41(uVar1,3);
        uStack_1c._0_3_ = CONCAT12(abStack_14[0],CONCAT11(uVar3,(char)uStack_1c));
        pvStack_18 = calloc(__nmemb,6);
        if (pvStack_18 == (void *)0x0) {
          if (__nmemb != 0) {
            uStack_1c = CONCAT31(uStack_1c._1_3_,0x8a);
            goto _L0;
          }
          puVar7 = (undefined2 *)0x0;
          bVar2 = 0;
        }
        else {
          puVar7 = (undefined2 *)0x0;
          bVar2 = 0;
        }
        while ((puVar7 = (undefined2 *)nwk_route_table_next(puVar7), puVar7 != (undefined2 *)0x0 &&
               (uStack_1c._3_1_ < __nmemb))) {
          if (abStack_14[0] <= bVar2) {
            *(undefined2 *)((uint)uStack_1c._3_1_ * 6 + (int)pvStack_18) = *puVar7;
            *(byte *)((int)pvStack_18 + (uint)uStack_1c._3_1_ * 6 + 2) =
                 *(byte *)((int)pvStack_18 + (uint)uStack_1c._3_1_ * 6 + 2) & 0xf8 |
                 (byte)puVar7[7] & 7;
            *(byte *)((int)pvStack_18 + (uint)uStack_1c._3_1_ * 6 + 2) =
                 (byte)((*(uint *)(puVar7 + 6) >> 0x13 & 1) << 3) |
                 *(byte *)((int)pvStack_18 + (uint)uStack_1c._3_1_ * 6 + 2) & 0xf7;
            *(byte *)((int)pvStack_18 + (uint)uStack_1c._3_1_ * 6 + 2) =
                 (byte)((*(uint *)(puVar7 + 6) >> 0x14 & 1) << 4) |
                 *(byte *)((int)pvStack_18 + (uint)uStack_1c._3_1_ * 6 + 2) & 0xef;
            *(byte *)((int)pvStack_18 + (uint)uStack_1c._3_1_ * 6 + 2) =
                 (byte)((*(uint *)(puVar7 + 6) >> 0x15 & 1) << 5) |
                 *(byte *)((int)pvStack_18 + (uint)uStack_1c._3_1_ * 6 + 2) & 0xdf;
            *(undefined2 *)((int)pvStack_18 + (uint)uStack_1c._3_1_ * 6 + 4) = puVar7[1];
            uStack_1c = CONCAT13(uStack_1c._3_1_ + 1,(undefined3)uStack_1c);
          }
          bVar2 = bVar2 + 1;
        }
      }
    }
  }
  else {
    uStack_1c = 0x84;
  }
_L0:
  cVar4 = (char)uStack_1c;
  if ((char)uStack_1c != -2) {
    cVar4 = zdo_op_nwk_mgmt_rtg_rsp(*(undefined4 *)(param_2 + 0x14),&uStack_1c,1);
  }
  uStack_1c = CONCAT31(uStack_1c._1_3_,cVar4);
  if (pvStack_18 != (void *)0x0) {
    mm_free();
  }
  return uStack_1c & 0xff;
}

