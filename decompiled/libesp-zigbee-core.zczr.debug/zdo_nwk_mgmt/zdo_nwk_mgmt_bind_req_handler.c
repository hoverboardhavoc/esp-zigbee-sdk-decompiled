/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_bind_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_nwk_mgmt_bind_req_handler(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint __nmemb;
  int iVar5;
  undefined2 *puVar6;
  byte bVar7;
  undefined2 local_48;
  undefined2 uStack_46;
  undefined2 uStack_44;
  undefined2 uStack_42;
  undefined2 local_40;
  undefined2 uStack_3e;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  char acStack_38 [4];
  undefined2 *puStack_34;
  undefined2 *puStack_30;
  int iStack_2c;
  void *pvStack_28;
  byte abStack_24 [8];
  
  abStack_24[0] = 0;
  iStack_2c = 0;
  pvStack_28 = (void *)0x0;
  if (param_1 == 0) {
    uVar4 = 0xfe;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    uVar4 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar4 = 0xfe;
  }
  else {
    iVar3 = zdo_op_nwk_mgmt_bind_req(abStack_24,0);
    if (iVar3 == 0) {
      aps_bind_table_iterator_init(0,acStack_38);
      bVar1 = 0;
      while (acStack_38[0] == '\0') {
        bVar1 = bVar1 + 1;
        aps_bind_table_iterator_next(acStack_38);
      }
      if ((bVar1 == 0) || (bVar1 <= abStack_24[0])) {
        iStack_2c = (uint)CONCAT11(abStack_24[0],bVar1) << 8;
        pvStack_28 = (void *)0x0;
        uVar4 = zdo_op_nwk_mgmt_bind_rsp(*(undefined4 *)(param_2 + 0x14),&iStack_2c,1);
      }
      else {
        __nmemb = zdo_nwk_mgmt_bind_get_max_entries();
        pvStack_28 = calloc(__nmemb,0x18);
        if ((pvStack_28 == (void *)0x0) && (__nmemb != 0)) {
          uVar4 = 0xfe;
        }
        else {
          aps_bind_table_iterator_init(0,acStack_38);
          uVar2 = 0;
          bVar7 = 0;
          while ((acStack_38[0] == '\0' && (uVar2 < __nmemb))) {
            if (abStack_24[0] <= bVar7) {
              iVar3 = nwk_address_extended_by_ref(*puStack_34,&local_48);
              if (iVar3 != 0) {
                return 0xfe;
              }
              iVar3 = uVar2 * 0x18;
              puVar6 = (undefined2 *)((int)pvStack_28 + iVar3);
              *puVar6 = local_48;
              puVar6[1] = uStack_46;
              puVar6[2] = uStack_44;
              puVar6[3] = uStack_42;
              *(undefined1 *)((int)pvStack_28 + iVar3 + 8) = *(undefined1 *)(puStack_34 + 1);
              *(undefined2 *)((int)pvStack_28 + iVar3 + 10) = puStack_34[2];
              if ((*(byte *)((int)puStack_30 + 5) & 1) == 0) {
                iVar5 = nwk_address_extended_by_ref(*puStack_30,&local_40);
                if (iVar5 != 0) {
                  return 0xfe;
                }
                *(undefined1 *)((int)pvStack_28 + iVar3 + 0xc) = 3;
                *(undefined2 *)((int)pvStack_28 + iVar3 + 0xe) = local_40;
                *(undefined2 *)((int)pvStack_28 + iVar3 + 0x10) = uStack_3e;
                *(undefined2 *)((int)pvStack_28 + iVar3 + 0x12) = uStack_3c;
                *(undefined2 *)((int)pvStack_28 + iVar3 + 0x14) = uStack_3a;
                *(undefined1 *)((int)pvStack_28 + iVar3 + 0x16) = *(undefined1 *)(puStack_30 + 1);
              }
              else {
                *(undefined1 *)((int)pvStack_28 + iVar3 + 0xc) = 1;
                *(undefined2 *)((int)pvStack_28 + iVar3 + 0xe) = *puStack_30;
                *(undefined1 *)((int)pvStack_28 + iVar3 + 0x16) = 0;
              }
              uVar2 = uVar2 + 1 & 0xff;
            }
            bVar7 = bVar7 + 1;
            aps_bind_table_iterator_next(acStack_38);
          }
          iStack_2c = (uint)CONCAT12((char)uVar2,CONCAT11(abStack_24[0],bVar1)) << 8;
          uVar4 = zdo_op_nwk_mgmt_bind_rsp(*(undefined4 *)(param_2 + 0x14),&iStack_2c,1);
          if (pvStack_28 != (void *)0x0) {
            mm_free();
          }
        }
      }
    }
    else {
      uVar4 = 0xfe;
    }
  }
  return uVar4;
}

