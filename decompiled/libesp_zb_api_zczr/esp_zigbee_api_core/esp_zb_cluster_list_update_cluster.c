/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> esp_zb_cluster_list_update_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_update_cluster(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  byte bVar2;
  ushort *__ptr;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined4 local_30;
  uint3 uStack_28;
  undefined1 uStack_25;
  undefined2 uStack_24;
  
  piVar4 = (int *)malloc(0x14);
  uVar1 = *(ushort *)(*(int *)(param_2 + 0xc) + 8);
  iVar5 = zcl_get_attr_lists(param_2);
  uVar3 = zcl_get_attr_count(param_2);
  if (param_1 == 0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_LC3,uVar6,"ESP_ZIGBEE_API_CORE");
    uVar6 = 0x102;
  }
  else {
    __ptr = *(ushort **)(param_1 + 0x10);
    while (__ptr != (ushort *)0x0) {
      if (*__ptr == uVar1) {
        bVar2 = (byte)param_3;
        if (uVar1 == 5) {
          local_30 = CONCAT22(uVar3,5);
          if (param_3 == 1) {
            puVar7 = &zb_zcl_scenes_init_server;
          }
          else if (param_3 == 2) {
            puVar7 = &zb_zcl_scenes_init_client;
          }
          else {
            puVar7 = (undefined *)0x0;
          }
          uStack_28 = (uint3)bVar2;
          _uStack_28 = CONCAT13((char)puVar7,uStack_28);
          uStack_24 = (undefined2)((uint)puVar7 >> 8);
          *piVar4 = local_30;
          piVar4[1] = iVar5;
          piVar4[2] = _uStack_28;
          *(undefined2 *)(piVar4 + 3) = uStack_24;
          *(undefined1 *)((int)piVar4 + 0xe) = 0;
          goto _L0;
        }
        if (uVar1 < 6) {
          if (uVar1 == 3) {
            local_30 = CONCAT22(uVar3,3);
            if (param_3 == 1) {
              puVar7 = &zb_zcl_identify_init_server;
            }
            else if (param_3 == 2) {
              puVar7 = &zb_zcl_identify_init_client;
            }
            else {
              puVar7 = (undefined *)0x0;
            }
            uStack_28 = (uint3)bVar2;
            _uStack_28 = CONCAT13((char)puVar7,uStack_28);
            uStack_24 = (undefined2)((uint)puVar7 >> 8);
            *piVar4 = local_30;
            piVar4[1] = iVar5;
            piVar4[2] = _uStack_28;
            *(undefined2 *)(piVar4 + 3) = uStack_24;
            *(undefined1 *)((int)piVar4 + 0xe) = 0;
            goto _L0;
          }
          if (uVar1 == 4) {
            local_30 = CONCAT22(uVar3,4);
            if (param_3 == 1) {
              puVar7 = &zb_zcl_groups_init_server;
            }
            else if (param_3 == 2) {
              puVar7 = &zb_zcl_groups_init_client;
            }
            else {
              puVar7 = (undefined *)0x0;
            }
            uStack_28 = (uint3)bVar2;
            _uStack_28 = CONCAT13((char)puVar7,uStack_28);
            uStack_24 = (undefined2)((uint)puVar7 >> 8);
            *piVar4 = local_30;
            piVar4[1] = iVar5;
            piVar4[2] = _uStack_28;
            *(undefined2 *)(piVar4 + 3) = uStack_24;
            *(undefined1 *)((int)piVar4 + 0xe) = 0;
            goto _L0;
          }
          if (uVar1 == 0) {
            local_30 = (uint)uVar3 << 0x10;
            if (param_3 == 1) {
              puVar7 = &zb_zcl_basic_init_server;
            }
            else if (param_3 == 2) {
              puVar7 = &zb_zcl_basic_init_client;
            }
            else {
              puVar7 = (undefined *)0x0;
            }
            uStack_28 = (uint3)bVar2;
            _uStack_28 = CONCAT13((char)puVar7,uStack_28);
            uStack_24 = (undefined2)((uint)puVar7 >> 8);
            *piVar4 = local_30;
            piVar4[1] = iVar5;
            piVar4[2] = _uStack_28;
            *(undefined2 *)(piVar4 + 3) = uStack_24;
            *(undefined1 *)((int)piVar4 + 0xe) = 0;
            goto _L0;
          }
        }
        else {
          if (uVar1 == 8) {
            local_30 = CONCAT22(uVar3,8);
            if (param_3 == 1) {
              puVar7 = &zb_zcl_level_control_init_server;
            }
            else if (param_3 == 2) {
              puVar7 = &zb_zcl_level_control_init_client;
            }
            else {
              puVar7 = (undefined *)0x0;
            }
            uStack_28 = (uint3)bVar2;
            _uStack_28 = CONCAT13((char)puVar7,uStack_28);
            uStack_24 = (undefined2)((uint)puVar7 >> 8);
            *piVar4 = local_30;
            piVar4[1] = iVar5;
            piVar4[2] = _uStack_28;
            *(undefined2 *)(piVar4 + 3) = uStack_24;
            *(undefined1 *)((int)piVar4 + 0xe) = 0;
            goto _L0;
          }
          if (uVar1 == 0x300) {
            local_30 = CONCAT22(uVar3,0x300);
            if (param_3 == 1) {
              puVar7 = &zb_zcl_color_control_init_server;
            }
            else if (param_3 == 2) {
              puVar7 = &zb_zcl_color_control_init_client;
            }
            else {
              puVar7 = (undefined *)0x0;
            }
            uStack_28 = (uint3)bVar2;
            _uStack_28 = CONCAT13((char)puVar7,uStack_28);
            uStack_24 = (undefined2)((uint)puVar7 >> 8);
            *piVar4 = local_30;
            piVar4[1] = iVar5;
            piVar4[2] = _uStack_28;
            *(undefined2 *)(piVar4 + 3) = uStack_24;
            *(undefined1 *)((int)piVar4 + 0xe) = 0;
            goto _L0;
          }
          if (uVar1 == 6) {
            local_30 = CONCAT22(uVar3,6);
            if (param_3 == 1) {
              puVar7 = &zb_zcl_on_off_init_server;
            }
            else if (param_3 == 2) {
              puVar7 = &zb_zcl_on_off_init_client;
            }
            else {
              puVar7 = (undefined *)0x0;
            }
            uStack_28 = (uint3)bVar2;
            _uStack_28 = CONCAT13((char)puVar7,uStack_28);
            uStack_24 = (undefined2)((uint)puVar7 >> 8);
            *piVar4 = local_30;
            piVar4[1] = iVar5;
            piVar4[2] = _uStack_28;
            *(undefined2 *)(piVar4 + 3) = uStack_24;
            *(undefined1 *)((int)piVar4 + 0xe) = 0;
            goto _L0;
          }
        }
        uVar6 = esp_log_timestamp();
        esp_log_write(2,"ESP_ZIGBEE_API_CORE",&_LC13,uVar6,"ESP_ZIGBEE_API_CORE",uVar1);
_L0:
        piVar4[4] = *(int *)(__ptr + 8);
        free(__ptr);
        *(int **)(param_1 + 0x10) = piVar4;
        return 0;
      }
      __ptr = *(ushort **)(__ptr + 8);
      if (__ptr == (ushort *)0x0) break;
      param_1 = *(int *)(param_1 + 0x10);
    }
    uVar6 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_API_CORE",&_LC14,uVar6,"ESP_ZIGBEE_API_CORE");
    uVar6 = 0x105;
  }
  return uVar6;
}

