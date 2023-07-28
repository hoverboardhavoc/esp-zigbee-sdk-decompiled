/*
 * Last changed at upstream commit 992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * https://github.com/espressif/esp-zigbee-sdk/commit/992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * Upstream date: 2023-07-28 17:48:58 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.7.2(e1472baa)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_device_attribute_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_device_attribute_update(undefined1 param_1,undefined4 param_2,ushort *param_3)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  ushort uStack_3c;
  byte bStack_3a;
  undefined1 uStack_39;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 uStack_34;
  undefined1 uStack_33;
  
  uVar2 = *param_3;
  uVar3 = param_3[1];
  if (uVar2 == 0x300) {
    if ((uVar3 == 3) && (uStack_3c = param_3[2], zcl_set_attr_user_cb != (code *)0x0)) {
      (*zcl_set_attr_user_cb)(param_1,0x300,3,&uStack_3c);
    }
    if ((uVar3 == 4) && (uStack_3c = param_3[2], zcl_set_attr_user_cb != (code *)0x0)) {
      (*zcl_set_attr_user_cb)(param_1,param_2,0x300,4,&uStack_3c);
    }
    if (uVar3 == 0) {
      uStack_3c = CONCAT11(uStack_3c._1_1_,(char)param_3[2]);
      if (zcl_set_attr_user_cb != (code *)0x0) {
        (*zcl_set_attr_user_cb)(param_1,param_2,0x300,0,&uStack_3c);
      }
    }
    if (uVar3 == 1) {
      uStack_3c = CONCAT11(uStack_3c._1_1_,(char)param_3[2]);
      if (zcl_set_attr_user_cb != (code *)0x0) {
        (*zcl_set_attr_user_cb)(param_1,param_2,0x300,1,&uStack_3c);
      }
    }
    if ((uVar3 == 7) && (uStack_3c = param_3[2], zcl_set_attr_user_cb != (code *)0x0)) {
      (*zcl_set_attr_user_cb)(param_1,param_2,0x300,7,&uStack_3c);
    }
    if (uVar3 != 0x4000) {
      return;
    }
    uStack_3c = param_3[2];
    if (zcl_set_attr_user_cb == (code *)0x0) {
      return;
    }
    (*zcl_set_attr_user_cb)(param_1,param_2,0x300,0x4000,&uStack_3c);
    return;
  }
  if (uVar2 < 0x301) {
    if (uVar2 == 6) {
      if (uVar3 != 0) {
        return;
      }
      if (zcl_set_attr_user_cb == (code *)0x0) {
        return;
      }
      uStack_3c = CONCAT11(uStack_3c._1_1_,(char)param_3[2]);
      (*zcl_set_attr_user_cb)(param_1,6,0,&uStack_3c);
      return;
    }
    if (uVar2 == 8) {
      if (uVar3 != 0) {
        return;
      }
      uStack_3c = CONCAT11(uStack_3c._1_1_,(char)param_3[2]);
      if (zcl_set_attr_user_cb == (code *)0x0) {
        return;
      }
      (*zcl_set_attr_user_cb)(param_1,8,0,&uStack_3c);
      return;
    }
  }
  else if (uVar2 == 0x500) {
    if (zcl_set_attr_user_cb == (code *)0x0) {
      return;
    }
    (*zcl_set_attr_user_cb)(param_1,0x500,uVar3,param_3 + 2);
    return;
  }
  if (uVar2 < 0xfc00) {
    uVar5 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC4,uVar5,"ESP_ZIGBEE_CORE",uVar2,uVar3);
  }
  else {
    iVar4 = esp_zb_zcl_get_cluster(param_2,uVar2,1);
    if (iVar4 != 0) {
      bVar1 = *(byte *)(iVar4 + 2);
      puVar8 = (ushort *)0x0;
      for (iVar7 = 0; iVar7 < (int)(uint)bVar1; iVar7 = iVar7 + 1) {
        puVar6 = (ushort *)(*(int *)(iVar4 + 4) + iVar7 * 10);
        uStack_3c = *puVar6;
        bStack_3a = (byte)puVar6[1];
        uStack_39 = *(undefined1 *)((int)puVar6 + 3);
        uStack_38 = (undefined1)puVar6[2];
        uStack_37 = *(undefined1 *)((int)puVar6 + 5);
        uStack_36 = (undefined1)puVar6[3];
        uStack_35 = *(undefined1 *)((int)puVar6 + 7);
        uStack_34 = (undefined1)puVar6[4];
        uStack_33 = *(undefined1 *)((int)puVar6 + 9);
        if (uStack_3c == uVar3) {
          if (((bStack_3a - 0x20 & 0xff) < 0xc) && ((0xb0bU >> (bStack_3a - 0x20 & 0x1f) & 1) != 0))
          {
            puVar8 = param_3 + 2;
          }
          else {
            uVar5 = esp_log_timestamp();
            esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC3,uVar5,"ESP_ZIGBEE_CORE");
            if (puVar8 == (ushort *)0x0) goto _L0;
          }
          if (zcl_set_attr_user_cb != (code *)0x0) {
            (*zcl_set_attr_user_cb)(param_1,param_2,uVar2,uVar3,puVar8);
          }
        }
_L0:
      }
    }
  }
  return;
}

