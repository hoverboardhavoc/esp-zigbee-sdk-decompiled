/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_power_desc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_power_desc_req_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  ushort uStack_1e;
  undefined4 uStack_1c;
  undefined2 uStack_18;
  ushort auStack_14 [4];
  
  auStack_14[0] = 0;
  uStack_1c = 0;
  uStack_18 = 0;
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
    iVar2 = zdo_op_power_desc_req(auStack_14,0);
    if (iVar2 == 0) {
      uVar1 = (uint)auStack_14[0];
      if (uVar1 < 0xfff8) {
        uStack_1c = CONCAT22(auStack_14[0],(undefined2)uStack_1c);
        uVar3 = nwk_get_short_address();
        if (uVar1 == uVar3) {
          uStack_1c = uStack_1c & 0xffffff00;
        }
        else {
          iVar2 = nwk_is_device_zed();
          if (iVar2 == 0) {
            uStack_1c = CONCAT31(uStack_1c._1_3_,0x81);
            puVar5 = (undefined2 *)0x0;
            do {
              do {
                puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5);
                if (puVar5 == (undefined2 *)0x0) goto _L0;
              } while ((*(uint *)(puVar5 + 6) & 3) != 2);
              uStack_1e = 0xffff;
              nwk_address_short_by_ref(*puVar5,&uStack_1e);
            } while (auStack_14[0] != uStack_1e);
          }
          else {
            uStack_1c = CONCAT31(uStack_1c._1_3_,0x80);
          }
        }
_L0:
        uStack_18 = 0;
        if (((uStack_1c & 0xff) == 0) &&
           (puVar5 = (undefined2 *)af_get_node_power_desc(), puVar5 != (undefined2 *)0x0)) {
          uStack_18 = *puVar5;
        }
        uVar4 = zdo_op_power_desc_rsp(*(undefined4 *)(param_2 + 0x14),&uStack_1c,1);
      }
      else {
        uVar4 = 0x8b;
      }
    }
    else {
      uVar4 = 0xfe;
    }
  }
  return uVar4;
}

