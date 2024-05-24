/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_electrical_measurement_cluster_get_measurement_profile_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_electrical_measurement_cluster_get_measurement_profile_resp(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 uVar7;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar2 == 0) {
    uVar7 = 0x104;
  }
  else {
    uVar7 = *(undefined2 *)(iVar2 + 1);
  }
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar5,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_electrical_measurement_cluster_get_measurement_profile_resp",0x701,
                  "esp_zb_zcl_electrical_measurement_cluster_get_measurement_profile_resp");
    pcVar4 = (char *)zb_zcl_get_ctx();
    *pcVar4 = *pcVar4 + '\x01';
  }
  else {
    puVar3 = (undefined1 *)zb_buf_reuse_func();
    *puVar3 = 0x19;
    pcVar4 = (char *)zb_zcl_get_ctx();
    cVar1 = *pcVar4;
    *pcVar4 = cVar1 + '\x01';
    puVar3[1] = cVar1;
    puVar3[2] = 1;
    puVar3 = (undefined1 *)zb_put_next_htole32(puVar3 + 3,*(undefined4 *)(param_1 + 0x10));
    *puVar3 = (char)*(undefined4 *)(param_1 + 0x14);
    puVar3[1] = (char)*(undefined4 *)(param_1 + 0x18);
    puVar3[2] = *(undefined1 *)(param_1 + 0x1c);
    uVar5 = zb_put_next_htole16(puVar3 + 3,*(undefined1 *)(param_1 + 0x1d));
    for (iVar6 = 0; iVar6 < (int)(uint)*(byte *)(param_1 + 0x1c); iVar6 = iVar6 + 1) {
    }
    zb_zcl_finish_and_send_packet
              (iVar2,uVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar7,*(undefined2 *)(param_1 + 0x24));
    zb_zcl_frame_get_sequence_number(iVar2);
  }
  return;
}

