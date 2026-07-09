/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_node_desc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_node_desc_req_handler(int param_1,int param_2)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  ushort uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  ushort auStack_14 [4];
  
  auStack_14[0] = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  if (param_1 == 0) {
    uVar5 = 0xfe;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    uVar5 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar5 = 0xfe;
  }
  else {
    iVar3 = zdo_op_node_desc_req(auStack_14,0);
    if (iVar3 == 0) {
      uVar1 = (uint)auStack_14[0];
      if (uVar1 < 0xfff8) {
        uStack_28 = CONCAT22(auStack_14[0],(undefined2)uStack_28);
        uVar4 = nwk_get_short_address();
        if (uVar1 == uVar4) {
          uStack_28 = uStack_28 & 0xffffff00;
        }
        else {
          iVar3 = nwk_is_device_zed();
          if (iVar3 == 0) {
            uStack_28 = CONCAT31(uStack_28._1_3_,0x81);
            puVar2 = (undefined2 *)0x0;
            do {
              do {
                puVar2 = (undefined2 *)nwk_neighbor_table_next(puVar2);
                if (puVar2 == (undefined2 *)0x0) goto _L0;
              } while ((*(uint *)(puVar2 + 6) & 3) != 2);
              uStack_2a = 0xffff;
              nwk_address_short_by_ref(*puVar2,&uStack_2a);
            } while (auStack_14[0] != uStack_2a);
          }
          else {
            uStack_28 = CONCAT31(uStack_28._1_3_,0x80);
          }
        }
_L0:
        uStack_24 = 0;
        uStack_20 = 0;
        uStack_1c = 0;
        uStack_18 = 0;
        if (((uStack_28 & 0xff) == 0) &&
           (puVar6 = (undefined4 *)af_get_node_desc(), puVar6 != (undefined4 *)0x0)) {
          uStack_24 = *puVar6;
          uStack_20 = puVar6[1];
          uStack_1c = puVar6[2];
          uStack_18 = puVar6[3];
        }
        uVar5 = zdo_op_node_desc_rsp(*(undefined4 *)(param_2 + 0x14),&uStack_28,1);
      }
      else {
        uVar5 = 0x8b;
      }
    }
    else {
      uVar5 = 0xfe;
    }
  }
  return uVar5;
}

