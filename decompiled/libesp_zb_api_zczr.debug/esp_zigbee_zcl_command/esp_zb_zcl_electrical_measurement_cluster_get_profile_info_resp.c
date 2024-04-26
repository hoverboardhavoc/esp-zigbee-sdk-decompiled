/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_electrical_measurement_cluster_get_profile_info_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_electrical_measurement_cluster_get_profile_info_resp(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 == 0) {
    uVar7 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar7,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_electrical_measurement_cluster_get_profile_info_resp",0x600,
                  *(undefined1 *)(param_1 + 9));
    pcVar6 = (char *)zb_zcl_get_ctx();
    *pcVar6 = *pcVar6 + '\x01';
  }
  else {
    iVar4 = zb_buf_get_out_func();
    if (iVar4 == 0) {
      uVar7 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar7,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_electrical_measurement_cluster_get_profile_info_resp",0x601,
                    "esp_zb_zcl_electrical_measurement_cluster_get_profile_info_resp");
      pcVar6 = (char *)zb_zcl_get_ctx();
      *pcVar6 = *pcVar6 + '\x01';
    }
    else {
      puVar5 = (undefined1 *)zb_buf_reuse_func();
      *puVar5 = 0x19;
      pcVar6 = (char *)zb_zcl_get_ctx();
      cVar1 = *pcVar6;
      *pcVar6 = cVar1 + '\x01';
      puVar5[1] = cVar1;
      puVar5[2] = 0;
      puVar5[3] = *(undefined1 *)(param_1 + 0x10);
      puVar5[4] = (char)*(undefined4 *)(param_1 + 0x14);
      puVar5[5] = *(undefined1 *)(param_1 + 0x18);
      puVar5 = puVar5 + 6;
      if ((*(short *)(param_1 + 0x1a) != 0) && (*(int *)(param_1 + 0x1c) != 0)) {
        for (iVar2 = 0; iVar2 < (int)(uint)*(ushort *)(param_1 + 0x1a); iVar2 = iVar2 + 1) {
          puVar5 = (undefined1 *)
                   zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x1c) + iVar2 * 2));
        }
      }
      zb_zcl_finish_and_send_packet
                (iVar4,puVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar3 + 1),
                 *(undefined2 *)(param_1 + 0x20));
      zb_zcl_frame_get_sequence_number(iVar4);
    }
  }
  return;
}

