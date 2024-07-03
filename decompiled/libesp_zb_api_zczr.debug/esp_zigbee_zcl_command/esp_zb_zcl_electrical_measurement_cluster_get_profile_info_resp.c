/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
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
  undefined1 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 == 0) {
    uVar7 = 0x104;
  }
  else {
    uVar7 = *(undefined2 *)(iVar3 + 1);
  }
  iVar3 = zb_buf_get_out_func();
  if (iVar3 == 0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar6,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_electrical_measurement_cluster_get_profile_info_resp",0x716,
                  "esp_zb_zcl_electrical_measurement_cluster_get_profile_info_resp");
    pcVar5 = (char *)zb_zcl_get_ctx();
    *pcVar5 = *pcVar5 + '\x01';
  }
  else {
    puVar4 = (undefined1 *)zb_buf_reuse_func();
    *puVar4 = 0x19;
    pcVar5 = (char *)zb_zcl_get_ctx();
    cVar1 = *pcVar5;
    *pcVar5 = cVar1 + '\x01';
    puVar4[1] = cVar1;
    puVar4[2] = 0;
    puVar4[3] = *(undefined1 *)(param_1 + 0x10);
    puVar4[4] = (char)*(undefined4 *)(param_1 + 0x14);
    puVar4[5] = *(undefined1 *)(param_1 + 0x18);
    puVar4 = puVar4 + 6;
    if ((*(short *)(param_1 + 0x1a) != 0) && (*(int *)(param_1 + 0x1c) != 0)) {
      for (iVar2 = 0; iVar2 < (int)(uint)*(ushort *)(param_1 + 0x1a); iVar2 = iVar2 + 1) {
        puVar4 = (undefined1 *)
                 zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x1c) + iVar2 * 2));
      }
    }
    zb_zcl_finish_and_send_packet
              (iVar3,puVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar7,0xb04);
    zb_zcl_frame_get_sequence_number(iVar3);
  }
  return;
}

