/*
 * Last changed at upstream commit 3ee1c52790580ff8c3ec33b61f57334e0f637dc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/3ee1c52790580ff8c3ec33b61f57334e0f637dc8
 * Upstream date: 2023-05-26 18:12:14 +0800
 * Upstream subject: esp-zboss: Provide zboss APIs to fix github issues(70cea8e)
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
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  ushort *puVar9;
  ushort uStack_3c;
  byte bStack_3a;
  undefined1 uStack_39;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 uStack_34;
  undefined1 uStack_33;
  
  uVar3 = (uint)*param_3;
  uVar2 = param_3[1];
  if (uVar3 == 8) {
    if ((uVar2 == 0) &&
       (uStack_3c = CONCAT11(uStack_3c._1_1_,(char)param_3[2]), zcl_set_attr_user_cb != (code *)0x0)
       ) {
      (*zcl_set_attr_user_cb)(param_1,8,0,&uStack_3c);
    }
  }
  else if (uVar3 == 0x300) {
    if ((uVar2 == 3) && (uStack_3c = param_3[2], zcl_set_attr_user_cb != (code *)0x0)) {
      (*zcl_set_attr_user_cb)(param_1,0x300,3,&uStack_3c);
    }
    if ((uVar2 == 4) && (uStack_3c = param_3[2], zcl_set_attr_user_cb != (code *)0x0)) {
      (*zcl_set_attr_user_cb)(param_1,param_2,0x300,4,&uStack_3c);
    }
    if (uVar2 == 0) {
      uStack_3c = CONCAT11(uStack_3c._1_1_,(char)param_3[2]);
      if (zcl_set_attr_user_cb != (code *)0x0) {
        (*zcl_set_attr_user_cb)(param_1,param_2,0x300,0,&uStack_3c);
      }
    }
    if (uVar2 == 1) {
      uStack_3c = CONCAT11(uStack_3c._1_1_,(char)param_3[2]);
      if (zcl_set_attr_user_cb != (code *)0x0) {
        (*zcl_set_attr_user_cb)(param_1,param_2,0x300,1,&uStack_3c);
      }
    }
    if ((uVar2 == 7) && (uStack_3c = param_3[2], zcl_set_attr_user_cb != (code *)0x0)) {
      (*zcl_set_attr_user_cb)(param_1,param_2,0x300,7,&uStack_3c);
    }
    if ((uVar2 == 0x4000) && (uStack_3c = param_3[2], zcl_set_attr_user_cb != (code *)0x0)) {
      (*zcl_set_attr_user_cb)(param_1,param_2,0x300,0x4000,&uStack_3c);
    }
  }
  else if (uVar3 == 6) {
    if ((uVar2 == 0) && (zcl_set_attr_user_cb != (code *)0x0)) {
      uStack_3c = CONCAT11(uStack_3c._1_1_,(char)param_3[2]);
      (*zcl_set_attr_user_cb)(param_1,6,0,&uStack_3c);
    }
  }
  else {
    uVar4 = esp_zb_get_global_custom_cluster_id();
    if (uVar4 == uVar3) {
      iVar6 = esp_zb_zcl_get_cluster(param_2,uVar3,1);
      bVar1 = *(byte *)(iVar6 + 2);
      puVar9 = (ushort *)0x0;
      for (iVar8 = 0; iVar8 < (int)(uint)bVar1; iVar8 = iVar8 + 1) {
        puVar7 = (ushort *)(*(int *)(iVar6 + 4) + iVar8 * 10);
        uStack_3c = *puVar7;
        bStack_3a = (byte)puVar7[1];
        uStack_39 = *(undefined1 *)((int)puVar7 + 3);
        uStack_38 = (undefined1)puVar7[2];
        uStack_37 = *(undefined1 *)((int)puVar7 + 5);
        uStack_36 = (undefined1)puVar7[3];
        uStack_35 = *(undefined1 *)((int)puVar7 + 7);
        uStack_34 = (undefined1)puVar7[4];
        uStack_33 = *(undefined1 *)((int)puVar7 + 9);
        if (uStack_3c == uVar2) {
          if (bStack_3a < 0x22) {
            if (bStack_3a < 0x20) {
_L0:
              uVar5 = esp_log_timestamp();
              esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC1,uVar5,"ESP_ZIGBEE_CORE");
              if (puVar9 == (ushort *)0x0) goto _L0;
            }
            else {
              puVar9 = param_3 + 2;
            }
          }
          else {
            if (bStack_3a != 0x23) goto _L0;
            puVar9 = param_3 + 2;
          }
          if (zcl_set_attr_user_cb != (code *)0x0) {
            (*zcl_set_attr_user_cb)(param_1,param_2,uVar3,uVar2,puVar9);
          }
        }
_L0:
      }
    }
    else {
      uVar5 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC2,uVar5,"ESP_ZIGBEE_CORE",uVar3,uVar2);
    }
  }
  return;
}

