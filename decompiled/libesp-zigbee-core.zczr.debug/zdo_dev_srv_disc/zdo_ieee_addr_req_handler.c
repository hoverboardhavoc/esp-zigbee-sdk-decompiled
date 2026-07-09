/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_ieee_addr_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_ieee_addr_req_handler(int param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  void *pvStack_28;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  pvStack_28 = (void *)0x0;
  if (param_1 == 0) {
    uVar8 = 0xfe;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    uVar8 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar8 = 0xfe;
  }
  else {
    iVar4 = zdo_op_ieee_addr_req(&uStack_24,0);
    if (iVar4 == 0) {
      uStack_38._0_2_ = CONCAT11(0xff,(undefined1)uStack_38);
      uStack_38._0_3_ = CONCAT12(0xff,(undefined2)uStack_38);
      uStack_38 = CONCAT13(0xff,(undefined3)uStack_38);
      uStack_34 = 0xffffffff;
      uStack_30 = CONCAT31(uStack_30._1_3_,0xff);
      uVar9 = uStack_24 & 0xffff;
      uVar5 = nwk_get_short_address();
      if (uVar9 == uVar5) {
        nwk_address_extended_by_short(uStack_24 & 0xffff,(int)&uStack_38 + 1);
      }
      else {
        puVar6 = (undefined2 *)nwk_neighbor_table_get_by_short(uStack_24 & 0xffff);
        if ((puVar6 != (undefined2 *)0x0) && ((*(uint *)(puVar6 + 6) & 3) == 2)) {
          nwk_address_extended_by_ref(*puVar6,(int)&uStack_38 + 1);
        }
      }
      if (((uStack_34 << 0x18 | uStack_38 >> 8) == 0xffffffff) &&
         ((uStack_30 << 0x18 | uStack_34 >> 8) == 0xffffffff)) {
        uStack_38 = CONCAT31(uStack_38._1_3_,0x81);
        uStack_30 = CONCAT22((undefined2)uStack_24,(undefined2)uStack_30);
        uVar8 = zdo_op_ieee_addr_rsp(*(undefined4 *)(param_2 + 0x14),uStack_24._2_1_,&uStack_38,1);
      }
      else if (uStack_24._2_1_ == '\0') {
        uStack_38 = (uint)uStack_38._1_3_ << 8;
        uStack_30 = CONCAT22((undefined2)uStack_24,(undefined2)uStack_30);
        nwk_address_extended_by_short((int)&uStack_38 + 1);
        uVar8 = zdo_op_ieee_addr_rsp
                          (*(undefined4 *)(param_2 + 0x14),uStack_24 >> 0x10 & 0xff,&uStack_38,1);
      }
      else if (uStack_24._2_1_ == '\x01') {
        uStack_38 = (uint)uStack_38._1_3_ << 8;
        puVar7 = (undefined4 *)nwk_get_extended_address();
        uVar8 = *puVar7;
        uVar2 = puVar7[1];
        uStack_38._0_2_ = CONCAT11((char)*(undefined3 *)puVar7,(undefined1)uStack_38);
        uStack_38._0_3_ = CONCAT12((char)((uint)uVar8 >> 8),(undefined2)uStack_38);
        uStack_38 = CONCAT13((char)((uint)uVar8 >> 0x10),(undefined3)uStack_38);
        uStack_34._0_2_ = CONCAT11((char)*(undefined3 *)(puVar7 + 1),(char)((uint)uVar8 >> 0x18));
        uStack_34._0_3_ = CONCAT12((char)((uint)uVar2 >> 8),(undefined2)uStack_34);
        uStack_34 = CONCAT13((char)((uint)uVar2 >> 0x10),(undefined3)uStack_34);
        uStack_30 = CONCAT31(uStack_30._1_3_,(char)((uint)uVar2 >> 0x18));
        uVar3 = nwk_get_short_address();
        uStack_30 = CONCAT22(uVar3,(undefined2)uStack_30);
        uStack_2c = (uint)CONCAT21(uStack_2c._2_2_,uStack_24._3_1_) << 8;
        iVar4 = nwk_is_device_zczr();
        if (iVar4 != 0) {
          uVar5 = nwk_neighbor_table_get_ed_num();
          if ((uVar5 & 0xff) != 0) {
            pvStack_28 = calloc(uVar5 & 0xff,2);
          }
          iVar4 = 0;
          uVar5 = 0;
          while (iVar4 = nwk_child_table_next(iVar4), iVar4 != 0) {
            if (((*(uint *)(iVar4 + 0xc) & 0x3c0) == 0x40) &&
               (uVar9 = uVar5 + 1 & 0xff, bVar1 = (uStack_2c >> 8 & 0xff) <= uVar5, uVar5 = uVar9,
               bVar1)) {
              uVar9 = uStack_2c & 0xff;
              uStack_2c = CONCAT31(uStack_2c._1_3_,(char)uStack_2c + '\x01');
              puVar6 = (undefined2 *)((int)pvStack_28 + uVar9 * 2);
              uVar3 = nwk_neighbor_get_shortaddr(iVar4);
              *puVar6 = uVar3;
            }
          }
        }
        uVar8 = zdo_op_ieee_addr_rsp
                          (*(undefined4 *)(param_2 + 0x14),uStack_24 >> 0x10 & 0xff,&uStack_38,1);
      }
      else {
        uStack_38 = CONCAT31(uStack_38._1_3_,0x80);
        puVar7 = (undefined4 *)nwk_get_extended_address();
        uVar8 = *puVar7;
        uVar2 = puVar7[1];
        uStack_38._0_2_ = CONCAT11((char)*(undefined3 *)puVar7,(undefined1)uStack_38);
        uStack_38._0_3_ = CONCAT12((char)((uint)uVar8 >> 8),(undefined2)uStack_38);
        uStack_38 = CONCAT13((char)((uint)uVar8 >> 0x10),(undefined3)uStack_38);
        uStack_34._0_2_ = CONCAT11((char)*(undefined3 *)(puVar7 + 1),(char)((uint)uVar8 >> 0x18));
        uStack_34._0_3_ = CONCAT12((char)((uint)uVar2 >> 8),(undefined2)uStack_34);
        uStack_34 = CONCAT13((char)((uint)uVar2 >> 0x10),(undefined3)uStack_34);
        uStack_30 = CONCAT31(uStack_30._1_3_,(char)((uint)uVar2 >> 0x18));
        uVar3 = nwk_get_short_address();
        uStack_30 = CONCAT22(uVar3,(undefined2)uStack_30);
        uVar8 = zdo_op_ieee_addr_rsp
                          (*(undefined4 *)(param_2 + 0x14),uStack_24 >> 0x10 & 0xff,&uStack_38,1);
      }
    }
    else {
      uVar8 = 0xfe;
    }
  }
  if (pvStack_28 != (void *)0x0) {
    mm_free();
  }
  return uVar8;
}

