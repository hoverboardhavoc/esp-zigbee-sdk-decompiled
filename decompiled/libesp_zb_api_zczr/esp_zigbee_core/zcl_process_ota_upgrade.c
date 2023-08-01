/*
 * Last changed at upstream commit 1f6b611e278a00f885edde9cb38294c3c08373a5
 * https://github.com/espressif/esp-zigbee-sdk/commit/1f6b611e278a00f885edde9cb38294c3c08373a5
 * Upstream date: 2023-08-01 20:17:41 +0800
 * Upstream subject: esp-zigbee-sdk: fix zigbee zcl scenes extension field implementation
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_process_ota_upgrade
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_process_ota_upgrade(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  if (zcl_ota_upgrade_status_user_cb != (code *)0x0) {
    (*zcl_ota_upgrade_status_user_cb)(*(undefined1 *)(param_1 + 0xc));
  }
  bVar1 = *(byte *)(param_1 + 0xc);
  if (bVar1 == 3) {
    iVar7 = esp_ota_end(update_handle);
    if (iVar7 != 0) {
      if (iVar7 == 0x1503) goto _L0;
      uVar4 = esp_log_timestamp();
      uVar3 = esp_err_to_name(iVar7);
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC28,uVar4,"ESP_ZIGBEE_CORE",uVar3);
    }
    do {
      iVar7 = esp_ota_set_boot_partition(update_partition);
      if (iVar7 != 0) {
        uVar4 = esp_log_timestamp();
        uVar3 = esp_err_to_name(iVar7);
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC29,uVar4,"ESP_ZIGBEE_CORE",uVar3);
      }
      uVar4 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_CORE",&_LC30,uVar4,"ESP_ZIGBEE_CORE");
      esp_restart();
_L0:
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC27,uVar4,"ESP_ZIGBEE_CORE",iVar7);
    } while( true );
  }
  if (bVar1 < 4) {
    if (bVar1 == 1) {
      *(undefined1 *)(param_1 + 0xc) = 6;
    }
    else if (bVar1 == 2) {
      uVar6 = *(uint *)(param_1 + 0x10);
      iVar7 = *(int *)(param_1 + 0x18);
      if ((uVar6 < 0x38) && (uVar5 = *(byte *)(param_1 + 0x14) + uVar6, 0x38 < uVar5)) {
        update_partition = esp_ota_get_next_update_partition(0);
        if (update_partition == 0) {
          __assert_func("//home/xieqinan/ESP/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_core.c",
                        0x2ee,"zcl_process_ota_upgrade","update_partition != NULL");
        }
        else {
          iVar2 = esp_ota_begin(0xfffffffe,&update_handle);
          if (iVar2 != 0) {
            uVar4 = esp_log_timestamp();
            uVar3 = esp_err_to_name(iVar2);
            esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC25,uVar4,"ESP_ZIGBEE_CORE",uVar3);
            return;
          }
        }
        iVar7 = esp_ota_write(update_handle,iVar7 + (0x38 - uVar6),uVar5 - 0x38);
        if (iVar7 != 0) {
          uVar4 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC26,uVar4,"ESP_ZIGBEE_CORE",iVar7);
          return;
        }
      }
      else if ((0x38 < uVar6) && (iVar7 = esp_ota_write(update_handle,iVar7), iVar7 != 0)) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC26,uVar4,"ESP_ZIGBEE_CORE",iVar7);
        return;
      }
      *(undefined1 *)(param_1 + 0xc) = 6;
    }
    else if (bVar1 == 0) {
      *(undefined1 *)(param_1 + 0xc) = 6;
    }
  }
  else if (bVar1 == 7) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC32,uVar4,"ESP_ZIGBEE_CORE");
  }
  else if (bVar1 == 10) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC31,uVar4,"ESP_ZIGBEE_CORE");
  }
  else if (bVar1 == 5) {
    *(undefined1 *)(param_1 + 0xc) = 6;
  }
  return;
}

