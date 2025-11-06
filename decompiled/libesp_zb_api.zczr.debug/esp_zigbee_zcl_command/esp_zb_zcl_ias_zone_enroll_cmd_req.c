/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_ias_zone_enroll_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_ias_zone_enroll_cmd_req(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar2 == 0) {
    uVar6 = 0x104;
  }
  else {
    uVar6 = *(undefined2 *)(iVar2 + 1);
  }
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): No I/O buffer for %s\n",uVar5,
            "ESP_ZIGBEE_COMMAND","esp_zb_zcl_ias_zone_enroll_cmd_req",0x59a,
            "esp_zb_zcl_ias_zone_enroll_cmd_req");
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
    zb_put_next_htole16(puVar3 + 3,*(undefined2 *)(param_1 + 0x10));
    uVar5 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x12));
    zb_zcl_finish_and_send_packet
              (iVar2,uVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar6,0x500);
    zb_zcl_frame_get_sequence_number(iVar2);
  }
  return;
}

