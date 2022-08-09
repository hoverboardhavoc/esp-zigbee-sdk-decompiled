/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> esp_zb_cluster_list_add_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_add_cluster(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  byte bVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort uVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined *puVar9;
  undefined4 local_30;
  uint3 uStack_28;
  undefined1 uStack_25;
  undefined2 uStack_24;
  
  piVar6 = (int *)malloc(0x14);
  uVar1 = *(ushort *)(*(int *)(param_2 + 0xc) + 8);
  if (param_1 == 0) {
    uVar8 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_LC3,uVar8,"ESP_ZIGBEE_API_CORE");
    return 0x102;
  }
  puVar3 = *(ushort **)(param_1 + 0x10);
  do {
    puVar4 = puVar3;
    if (puVar4 == (ushort *)0x0) break;
    if (*puVar4 == uVar1 && (byte)puVar4[4] == param_3) {
      uVar8 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_L0,uVar8,"ESP_ZIGBEE_API_CORE",uVar1);
      return 0x102;
    }
    puVar3 = *(ushort **)(puVar4 + 8);
  } while (*(ushort **)(puVar4 + 8) != (ushort *)0x0);
  iVar7 = zcl_get_attr_lists(param_2);
  uVar5 = zcl_get_attr_count(param_2);
  bVar2 = (byte)param_3;
  if (uVar1 == 5) {
    local_30 = CONCAT22(uVar5,5);
    if (param_3 == 1) {
      puVar9 = &zb_zcl_scenes_init_server;
    }
    else if (param_3 == 2) {
      puVar9 = &zb_zcl_scenes_init_client;
    }
    else {
      puVar9 = (undefined *)0x0;
    }
    uStack_28 = (uint3)bVar2;
    _uStack_28 = CONCAT13((char)puVar9,uStack_28);
    uStack_24 = (undefined2)((uint)puVar9 >> 8);
    *piVar6 = local_30;
    piVar6[1] = iVar7;
    piVar6[2] = _uStack_28;
    *(undefined2 *)(piVar6 + 3) = uStack_24;
    *(undefined1 *)((int)piVar6 + 0xe) = 0;
    goto _L0;
  }
  if (uVar1 < 6) {
    if (uVar1 == 3) {
      local_30 = CONCAT22(uVar5,3);
      if (param_3 == 1) {
        puVar9 = &zb_zcl_identify_init_server;
      }
      else if (param_3 == 2) {
        puVar9 = &zb_zcl_identify_init_client;
      }
      else {
        puVar9 = (undefined *)0x0;
      }
      uStack_28 = (uint3)bVar2;
      _uStack_28 = CONCAT13((char)puVar9,uStack_28);
      uStack_24 = (undefined2)((uint)puVar9 >> 8);
      *piVar6 = local_30;
      piVar6[1] = iVar7;
      piVar6[2] = _uStack_28;
      *(undefined2 *)(piVar6 + 3) = uStack_24;
      *(undefined1 *)((int)piVar6 + 0xe) = 0;
      goto _L0;
    }
    if (uVar1 == 4) {
      local_30 = CONCAT22(uVar5,4);
      if (param_3 == 1) {
        puVar9 = &zb_zcl_groups_init_server;
      }
      else if (param_3 == 2) {
        puVar9 = &zb_zcl_groups_init_client;
      }
      else {
        puVar9 = (undefined *)0x0;
      }
      uStack_28 = (uint3)bVar2;
      _uStack_28 = CONCAT13((char)puVar9,uStack_28);
      uStack_24 = (undefined2)((uint)puVar9 >> 8);
      *piVar6 = local_30;
      piVar6[1] = iVar7;
      piVar6[2] = _uStack_28;
      *(undefined2 *)(piVar6 + 3) = uStack_24;
      *(undefined1 *)((int)piVar6 + 0xe) = 0;
      goto _L0;
    }
    if (uVar1 == 0) {
      local_30 = (uint)uVar5 << 0x10;
      if (param_3 == 1) {
        puVar9 = &zb_zcl_basic_init_server;
      }
      else if (param_3 == 2) {
        puVar9 = &zb_zcl_basic_init_client;
      }
      else {
        puVar9 = (undefined *)0x0;
      }
      uStack_28 = (uint3)bVar2;
      _uStack_28 = CONCAT13((char)puVar9,uStack_28);
      uStack_24 = (undefined2)((uint)puVar9 >> 8);
      *piVar6 = local_30;
      piVar6[1] = iVar7;
      piVar6[2] = _uStack_28;
      *(undefined2 *)(piVar6 + 3) = uStack_24;
      *(undefined1 *)((int)piVar6 + 0xe) = 0;
      goto _L0;
    }
  }
  else {
    if (uVar1 == 8) {
      local_30 = CONCAT22(uVar5,8);
      if (param_3 == 1) {
        puVar9 = &zb_zcl_level_control_init_server;
      }
      else if (param_3 == 2) {
        puVar9 = &zb_zcl_level_control_init_client;
      }
      else {
        puVar9 = (undefined *)0x0;
      }
      uStack_28 = (uint3)bVar2;
      _uStack_28 = CONCAT13((char)puVar9,uStack_28);
      uStack_24 = (undefined2)((uint)puVar9 >> 8);
      *piVar6 = local_30;
      piVar6[1] = iVar7;
      piVar6[2] = _uStack_28;
      *(undefined2 *)(piVar6 + 3) = uStack_24;
      *(undefined1 *)((int)piVar6 + 0xe) = 0;
      goto _L0;
    }
    if (uVar1 == 0x300) {
      local_30 = CONCAT22(uVar5,0x300);
      if (param_3 == 1) {
        puVar9 = &zb_zcl_color_control_init_server;
      }
      else if (param_3 == 2) {
        puVar9 = &zb_zcl_color_control_init_client;
      }
      else {
        puVar9 = (undefined *)0x0;
      }
      uStack_28 = (uint3)bVar2;
      _uStack_28 = CONCAT13((char)puVar9,uStack_28);
      uStack_24 = (undefined2)((uint)puVar9 >> 8);
      *piVar6 = local_30;
      piVar6[1] = iVar7;
      piVar6[2] = _uStack_28;
      *(undefined2 *)(piVar6 + 3) = uStack_24;
      *(undefined1 *)((int)piVar6 + 0xe) = 0;
      goto _L0;
    }
    if (uVar1 == 6) {
      local_30 = CONCAT22(uVar5,6);
      if (param_3 == 1) {
        puVar9 = &zb_zcl_on_off_init_server;
      }
      else if (param_3 == 2) {
        puVar9 = &zb_zcl_on_off_init_client;
      }
      else {
        puVar9 = (undefined *)0x0;
      }
      uStack_28 = (uint3)bVar2;
      _uStack_28 = CONCAT13((char)puVar9,uStack_28);
      uStack_24 = (undefined2)((uint)puVar9 >> 8);
      *piVar6 = local_30;
      piVar6[1] = iVar7;
      piVar6[2] = _uStack_28;
      *(undefined2 *)(piVar6 + 3) = uStack_24;
      *(undefined1 *)((int)piVar6 + 0xe) = 0;
      goto _L0;
    }
  }
  uVar8 = esp_log_timestamp();
  esp_log_write(2,"ESP_ZIGBEE_API_CORE",&_LC13,uVar8,"ESP_ZIGBEE_API_CORE",uVar1);
_L0:
  piVar6[4] = 0;
  if (puVar4 == (ushort *)0x0) {
    *(int **)(param_1 + 0x10) = piVar6;
  }
  else {
    *(int **)(puVar4 + 8) = piVar6;
  }
  return 0;
}

