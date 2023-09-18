/*
 * Last changed at upstream commit 6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * https://github.com/espressif/esp-zigbee-sdk/commit/6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * Upstream date: 2023-09-18 10:30:22 +0800
 * Upstream subject: esp-zigbee-sdk: add zigbee trace support and assert support(8c01f3c7)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_ota_upgrade_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_ota_upgrade_handler(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  undefined2 uStack_26;
  uint uStack_24;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  uStack_2c = 0;
  uStack_28 = *(undefined1 *)(iVar2 + 4);
  uStack_26 = 0x19;
  uStack_24 = (uint)*(byte *)(iVar2 + 0xc);
  if (zb_core_action_cb == (code *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (*zb_core_action_cb)(4,&uStack_2c);
  }
  bVar1 = *(byte *)(iVar2 + 0xc);
  if (bVar1 == 3) {
    iVar2 = esp_ota_end(update_handle);
    if (iVar2 != 0) {
      if (iVar2 == 0x1503) goto _L0;
      uVar5 = esp_log_timestamp();
      uVar4 = esp_err_to_name(iVar2);
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC36,uVar5,"ESP_ZIGBEE_CORE",uVar4);
    }
    do {
      iVar2 = esp_ota_set_boot_partition(update_partition);
      if (iVar2 != 0) {
        uVar5 = esp_log_timestamp();
        uVar4 = esp_err_to_name(iVar2);
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC37,uVar5,"ESP_ZIGBEE_CORE",uVar4);
      }
      uVar5 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_CORE",&_LC38,uVar5,"ESP_ZIGBEE_CORE");
      esp_restart();
_L0:
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC35,uVar5,"ESP_ZIGBEE_CORE",iVar2);
    } while( true );
  }
  if (bVar1 < 4) {
    if (bVar1 == 1) {
      *(undefined1 *)(iVar2 + 0xc) = 6;
    }
    else if (bVar1 == 2) {
      uVar7 = *(uint *)(iVar2 + 0x10);
      iVar8 = *(int *)(iVar2 + 0x18);
      if ((uVar7 < 0x38) && (uVar6 = *(byte *)(iVar2 + 0x14) + uVar7, 0x38 < uVar6)) {
        update_partition = esp_ota_get_next_update_partition(0);
        if (update_partition == 0) {
          __assert_func("//home/xiaqilin/esp/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_core.c",
                        0x3d1,"zcl_ota_upgrade_handler","update_partition != NULL");
        }
        else {
          iVar3 = esp_ota_begin(0xfffffffe,&update_handle);
          if (iVar3 != 0) {
            uVar5 = esp_log_timestamp();
            uVar4 = esp_err_to_name(iVar3);
            esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC33,uVar5,"ESP_ZIGBEE_CORE",uVar4);
            goto _L0;
          }
        }
        iVar3 = esp_ota_write(update_handle,iVar8 + (0x38 - uVar7),uVar6 - 0x38);
        if (iVar3 == 0) {
          *(undefined1 *)(iVar2 + 0xc) = 6;
          return 0;
        }
        uVar5 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC34,uVar5,"ESP_ZIGBEE_CORE",iVar3);
      }
      else if (uVar7 < 0x39) {
        *(undefined1 *)(iVar2 + 0xc) = 6;
      }
      else {
        iVar3 = esp_ota_write(update_handle,iVar8);
        if (iVar3 == 0) {
          *(undefined1 *)(iVar2 + 0xc) = 6;
          return 0;
        }
        uVar5 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC34,uVar5,"ESP_ZIGBEE_CORE",iVar3);
      }
    }
    else if (bVar1 == 0) {
      *(undefined1 *)(iVar2 + 0xc) = 6;
    }
  }
  else if (bVar1 == 7) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC40,uVar5,"ESP_ZIGBEE_CORE");
  }
  else if (bVar1 == 10) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC39,uVar5,"ESP_ZIGBEE_CORE");
  }
  else if (bVar1 == 5) {
    *(undefined1 *)(iVar2 + 0xc) = 6;
  }
_L0:
  if (iVar3 != 0) {
    iVar3 = -1;
  }
  return iVar3;
}

