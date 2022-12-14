/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_ota_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ota_cluster_create(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = esp_zb_zcl_attr_list_create(0x19);
  if (param_1 == 0) {
    esp_zb_ota_cluster_add_attr(2,&lu32_ota_upgrade_file_version_7);
    esp_zb_ota_cluster_add_attr(uVar1,7,&lu16_ota_upgrade_manufacturer_6);
    esp_zb_ota_cluster_add_attr(uVar1,8,&lu16_ota_upgrade_image_type_5);
    esp_zb_ota_cluster_add_attr(uVar1,0,&leui64_ota_upgrade_server_id_4);
    esp_zb_ota_cluster_add_attr(uVar1,6,&lu8_ota_image_upgrade_status_3);
    esp_zb_ota_cluster_add_attr(uVar1,9,&lu16_ota_min_block_reque_2);
    esp_zb_ota_cluster_add_attr(uVar1,1,&lu32_ota_upgrade_file_offset_1);
    esp_zb_ota_cluster_add_attr(uVar1,4,&lu32_ota_upgrade_downloaded_file_ver_0);
  }
  else {
    esp_zb_ota_cluster_add_attr(2,param_1);
    esp_zb_ota_cluster_add_attr(uVar1,7,param_1 + 4);
    esp_zb_ota_cluster_add_attr(uVar1,8,param_1 + 6);
    esp_zb_ota_cluster_add_attr(uVar1,0,param_1 + 0x14);
    esp_zb_ota_cluster_add_attr(uVar1,6,param_1 + 0x1c);
    esp_zb_ota_cluster_add_attr(uVar1,9,param_1 + 8);
    esp_zb_ota_cluster_add_attr(uVar1,1,param_1 + 0xc);
    esp_zb_ota_cluster_add_attr(uVar1,4,param_1 + 0x10);
  }
  return uVar1;
}

