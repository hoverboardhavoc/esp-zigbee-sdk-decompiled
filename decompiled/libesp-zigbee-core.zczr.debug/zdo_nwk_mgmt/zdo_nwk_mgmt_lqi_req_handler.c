/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_lqi_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_nwk_mgmt_lqi_req_handler(int param_1,int param_2)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  int iVar5;
  int *piVar6;
  uint __nmemb;
  undefined4 uVar7;
  int iVar8;
  undefined2 *puVar9;
  uint uVar10;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  void *pvStack_28;
  byte abStack_24 [4];
  
  abStack_24[0] = 0;
  iStack_2c = 0;
  pvStack_28 = (void *)0x0;
  if (param_1 == 0) {
    uVar7 = 0xfe;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    uVar7 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar7 = 0xfe;
  }
  else {
    iVar5 = zdo_op_nwk_mgmt_lqi_req(abStack_24,0);
    if (iVar5 == 0) {
      uStack_34 = 0;
      uStack_30 = 0;
      uVar2 = nwk_neighbor_table_get_size();
      piVar6 = (int *)nwk_get_extended_panid();
      uStack_34 = *piVar6;
      uStack_30 = piVar6[1];
      if (uStack_34 == 0 && uStack_30 == 0) {
        uVar7 = 0xfe;
      }
      else if ((uStack_34 == -1) && (uStack_30 == -1)) {
        uVar7 = 0xfe;
      }
      else {
        __nmemb = zdo_nwk_mgmt_lqi_get_max_entries();
        pvStack_28 = calloc(__nmemb,0x16);
        if (pvStack_28 == (void *)0x0) {
          if (__nmemb != 0) {
            uVar7 = 0xfe;
            goto _L0;
          }
          iVar5 = 0;
          bVar1 = 0;
          uVar10 = 0;
        }
        else {
          iVar5 = 0;
          bVar1 = 0;
          uVar10 = 0;
        }
        while ((iVar5 = nwk_neighbor_table_next(iVar5), iVar5 != 0 && (uVar10 < __nmemb))) {
          if (abStack_24[0] <= bVar1) {
            nwk_neighbor_get_extaddr(iVar5,&uStack_3c);
            uVar4 = nwk_neighbor_get_shortaddr(iVar5);
            uVar3 = nwk_neighbor_get_lqa(iVar5);
            iVar8 = uVar10 * 0x16;
            puVar9 = (undefined2 *)((int)pvStack_28 + iVar8);
            *puVar9 = (undefined2)uStack_34;
            puVar9[1] = uStack_34._2_2_;
            puVar9[2] = (undefined2)uStack_30;
            puVar9[3] = uStack_30._2_2_;
            *(undefined2 *)((int)pvStack_28 + iVar8 + 8) = uStack_3c;
            *(undefined2 *)((int)pvStack_28 + iVar8 + 10) = uStack_3a;
            *(undefined2 *)((int)pvStack_28 + iVar8 + 0xc) = uStack_38;
            *(undefined2 *)((int)pvStack_28 + iVar8 + 0xe) = uStack_36;
            *(undefined2 *)((int)pvStack_28 + iVar8 + 0x10) = uVar4;
            *(ushort *)((int)pvStack_28 + iVar8 + 0x12) =
                 *(ushort *)((int)pvStack_28 + iVar8 + 0x12) & 0xfffc |
                 (ushort)*(undefined4 *)(iVar5 + 0xc) & 3;
            *(ushort *)((int)pvStack_28 + iVar8 + 0x12) =
                 (ushort)((*(uint *)(iVar5 + 0xc) >> 10 & 1) << 2) |
                 *(ushort *)((int)pvStack_28 + iVar8 + 0x12) & 0xfff3;
            *(ushort *)((int)pvStack_28 + iVar8 + 0x12) =
                 (ushort)((*(uint *)(iVar5 + 0xc) >> 6 & 7) << 4) |
                 *(ushort *)((int)pvStack_28 + iVar8 + 0x12) & 0xff8f;
            *(ushort *)((int)pvStack_28 + iVar8 + 0x12) =
                 (ushort)((*(uint *)(iVar5 + 0xc) >> 0xb & 1) << 8) |
                 *(ushort *)((int)pvStack_28 + iVar8 + 0x12) & 0xfcff;
            *(byte *)((int)pvStack_28 + iVar8 + 0x14) = (byte)(*(uint *)(iVar5 + 0xc) >> 2) & 0xf;
            *(undefined1 *)((int)pvStack_28 + iVar8 + 0x15) = uVar3;
            uVar10 = uVar10 + 1 & 0xff;
          }
          bVar1 = bVar1 + 1;
        }
        iStack_2c = (uint)CONCAT12((char)uVar10,CONCAT11(abStack_24[0],uVar2)) << 8;
        uVar7 = zdo_op_nwk_mgmt_lqi_rsp(*(undefined4 *)(param_2 + 0x14),&iStack_2c,1);
      }
    }
    else {
      uVar7 = 0xfe;
    }
  }
_L0:
  if (pvStack_28 != (void *)0x0) {
    mm_free();
  }
  return uVar7;
}

