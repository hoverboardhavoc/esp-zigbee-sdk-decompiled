/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_nwk_addr_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_nwk_addr_req_handler(int param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  int iVar5;
  int *piVar6;
  undefined2 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined1 uVar10;
  undefined1 uVar12;
  undefined1 uVar15;
  uint uVar17;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  void *pvStack_30;
  int iStack_2c;
  int iStack_28;
  undefined2 uStack_24;
  undefined1 uVar11;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar16;
  
  iStack_2c = 0;
  iStack_28 = 0;
  uStack_24 = 0;
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  pvStack_30 = (void *)0x0;
  if (param_1 == 0) {
    uVar3 = 0xfe;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    uVar3 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar3 = 0xfe;
  }
  else {
    iVar5 = zdo_op_nwk_addr_req(&iStack_2c,0);
    if (iVar5 == 0) {
      local_40._0_2_ = CONCAT11((char)iStack_2c,(undefined1)local_40);
      local_40._0_3_ = CONCAT12((char)((uint)iStack_2c >> 8),(undefined2)local_40);
      local_40 = CONCAT13((char)((uint)iStack_2c >> 0x10),(undefined3)local_40);
      uStack_3c._0_2_ = CONCAT11((char)iStack_28,(char)((uint)iStack_2c >> 0x18));
      uStack_3c._0_3_ = CONCAT12((char)((uint)iStack_28 >> 8),(undefined2)uStack_3c);
      uStack_3c = CONCAT13((char)((uint)iStack_28 >> 0x10),(undefined3)uStack_3c);
      uStack_38 = CONCAT31(uStack_38._1_3_,(char)((uint)iStack_28 >> 0x18));
      uStack_38 = CONCAT22(0xffff,(undefined2)uStack_38);
      piVar6 = (int *)nwk_get_extended_address();
      if ((*piVar6 == iStack_2c) && (piVar6[1] == iStack_28)) {
        nwk_address_short_by_extended(&iStack_2c,(int)&uStack_38 + 2);
      }
      else {
        puVar7 = (undefined2 *)nwk_neighbor_table_get_by_extended(&iStack_2c);
        if ((puVar7 != (undefined2 *)0x0) && ((*(uint *)(puVar7 + 6) & 3) == 2)) {
          nwk_address_short_by_ref(*puVar7,(int)&uStack_38 + 2);
        }
      }
      bVar1 = uStack_38._2_2_ == -1;
      uVar10 = (undefined1)((uint)iStack_2c >> 8);
      uVar11 = (undefined1)((uint)iStack_2c >> 0x10);
      uVar12 = (undefined1)((uint)iStack_2c >> 0x18);
      uVar15 = (undefined1)iStack_28;
      uVar13 = (undefined1)((uint)iStack_28 >> 8);
      uVar14 = (undefined1)((uint)iStack_28 >> 0x10);
      uVar16 = (undefined1)((uint)iStack_28 >> 0x18);
      if (bVar1) {
        if (*(ushort *)(param_1 + 2) < 0xfff8) {
          local_40._0_2_ = CONCAT11((char)iStack_2c,0x81);
          local_40._0_3_ = CONCAT12(uVar10,(undefined2)local_40);
          local_40 = CONCAT13(uVar11,(undefined3)local_40);
          uStack_3c._0_2_ = CONCAT11(uVar15,uVar12);
          uStack_3c._0_3_ = CONCAT12(uVar13,(undefined2)uStack_3c);
          uStack_3c = CONCAT13(uVar14,(undefined3)uStack_3c);
          uStack_38 = CONCAT31(uStack_38._1_3_,uVar16);
          uStack_38 = CONCAT22(0xffff,(undefined2)uStack_38);
          uVar3 = zdo_op_nwk_addr_rsp(*(undefined4 *)(param_2 + 0x14),(char)uStack_24,&local_40,1);
        }
        else {
          uVar3 = 0xfe;
        }
      }
      else if ((char)uStack_24 == '\0') {
        local_40 = iStack_2c << 8;
        uStack_3c._0_2_ = CONCAT11(uVar15,uVar12);
        uStack_3c._0_3_ = CONCAT12(uVar13,(undefined2)uStack_3c);
        uStack_3c = CONCAT13(uVar14,(undefined3)uStack_3c);
        uStack_38 = CONCAT31(uStack_38._1_3_,uVar16);
        nwk_address_short_by_extended((int)&local_40 + 1,(int)&uStack_38 + 2);
        uVar3 = zdo_op_nwk_addr_rsp(*(undefined4 *)(param_2 + 0x14),(char)uStack_24,&local_40,1);
      }
      else if ((char)uStack_24 == '\x01') {
        iVar5 = nwk_is_device_zczr();
        if (iVar5 != 0) {
          local_40 = local_40 & 0xffffff00;
          puVar8 = (undefined4 *)nwk_get_extended_address();
          uVar3 = *puVar8;
          uVar2 = puVar8[1];
          local_40._0_2_ = CONCAT11((char)*(undefined3 *)puVar8,(undefined1)local_40);
          local_40._0_3_ = CONCAT12((char)((uint)uVar3 >> 8),(undefined2)local_40);
          local_40 = CONCAT13((char)((uint)uVar3 >> 0x10),(undefined3)local_40);
          uStack_3c._0_2_ = CONCAT11((char)*(undefined3 *)(puVar8 + 1),(char)((uint)uVar3 >> 0x18));
          uStack_3c._0_3_ = CONCAT12((char)((uint)uVar2 >> 8),(undefined2)uStack_3c);
          uStack_3c = CONCAT13((char)((uint)uVar2 >> 0x10),(undefined3)uStack_3c);
          uStack_38 = CONCAT31(uStack_38._1_3_,(char)((uint)uVar2 >> 0x18));
          uVar4 = nwk_get_short_address();
          uStack_38 = CONCAT22(uVar4,(undefined2)uStack_38);
          uVar9 = nwk_neighbor_table_get_ed_num();
          uVar9 = uVar9 & 0xff;
          if (uVar9 != 0) {
            pvStack_30 = calloc(uVar9,2);
          }
          uStack_34 = (uint)CONCAT21(uStack_34._2_2_,uStack_24._1_1_) << 8;
          puVar7 = (undefined2 *)0x0;
          uVar17 = 0;
          while ((puVar7 = (undefined2 *)nwk_neighbor_table_next(puVar7),
                 puVar7 != (undefined2 *)0x0 && ((uStack_34 & 0xff) < uVar9))) {
            if (((uStack_34 >> 8 & 0xff) <= uVar17) && ((*(uint *)(puVar7 + 6) & 3) == 2)) {
              nwk_address_short_by_ref(*puVar7,(void *)((int)pvStack_30 + (uStack_34 & 0xff) * 2));
              uStack_34 = CONCAT31(uStack_34._1_3_,(char)uStack_34 + '\x01');
            }
            uVar17 = uVar17 + 1 & 0xff;
          }
        }
        uVar3 = zdo_op_nwk_addr_rsp(*(undefined4 *)(param_2 + 0x14),(char)uStack_24,&local_40,1);
      }
      else if (*(ushort *)(param_1 + 2) < 0xfff8) {
        local_40._0_2_ = CONCAT11((char)iStack_2c,0x80);
        local_40._0_3_ = CONCAT12(uVar10,(undefined2)local_40);
        local_40 = CONCAT13(uVar11,(undefined3)local_40);
        uStack_3c._0_2_ = CONCAT11(uVar15,uVar12);
        uStack_3c._0_3_ = CONCAT12(uVar13,(undefined2)uStack_3c);
        uStack_3c = CONCAT13(uVar14,(undefined3)uStack_3c);
        uStack_38 = CONCAT31(uStack_38._1_3_,uVar16);
        nwk_address_short_by_extended((int)&local_40 + 1,(int)&uStack_38 + 2);
        uVar3 = zdo_op_nwk_addr_rsp(*(undefined4 *)(param_2 + 0x14),(char)uStack_24,&local_40,1);
      }
      else {
        uVar3 = 0xfe;
      }
    }
    else {
      uVar3 = 0xfe;
    }
  }
  if (pvStack_30 != (void *)0x0) {
    mm_free();
  }
  return uVar3;
}

