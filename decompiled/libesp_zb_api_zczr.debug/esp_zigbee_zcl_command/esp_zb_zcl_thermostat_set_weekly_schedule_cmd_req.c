/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_thermostat_set_weekly_schedule_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_thermostat_set_weekly_schedule_cmd_req(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar2 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar5,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_thermostat_set_weekly_schedule_cmd_req",0x64c,
                  *(undefined1 *)(param_1 + 9));
    pcVar6 = (char *)zb_zcl_get_ctx();
    *pcVar6 = *pcVar6 + '\x01';
  }
  else {
    iVar3 = zb_buf_get_out_func();
    if (iVar3 == 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar5,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_thermostat_set_weekly_schedule_cmd_req",0x64d,
                    "esp_zb_zcl_thermostat_set_weekly_schedule_cmd_req");
      pcVar6 = (char *)zb_zcl_get_ctx();
      *pcVar6 = *pcVar6 + '\x01';
    }
    else {
      puVar4 = (undefined1 *)zb_zcl_start_command_header(1,0,1,0);
      *puVar4 = *(undefined1 *)(param_1 + 0x10);
      puVar4[1] = *(undefined1 *)(param_1 + 0x11);
      puVar4[2] = *(undefined1 *)(param_1 + 0x12);
      uVar5 = zb_put_next_htole16(puVar4 + 3,*(undefined2 *)(param_1 + 0x14));
      cVar1 = *(char *)(param_1 + 0x12);
      if (cVar1 == '\x01') {
        uVar5 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x16));
      }
      else if (cVar1 == '\x02') {
        uVar5 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x18));
      }
      else if (cVar1 == '\x03') {
        zb_put_next_htole16(*(undefined2 *)(param_1 + 0x16));
        uVar5 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x18));
      }
      zb_zcl_finish_and_send_packet
                (iVar3,uVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar2 + 1),0x201);
      zb_zcl_frame_get_sequence_number(iVar3);
    }
  }
  return;
}

