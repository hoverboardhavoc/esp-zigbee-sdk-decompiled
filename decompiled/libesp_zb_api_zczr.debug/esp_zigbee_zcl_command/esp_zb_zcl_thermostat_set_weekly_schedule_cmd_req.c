/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
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
  undefined1 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
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
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar4,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_thermostat_set_weekly_schedule_cmd_req",0x731,
                  "esp_zb_zcl_thermostat_set_weekly_schedule_cmd_req");
    pcVar5 = (char *)zb_zcl_get_ctx();
    *pcVar5 = *pcVar5 + '\x01';
  }
  else {
    puVar3 = (undefined1 *)zb_zcl_start_command_header(1,0,1,0);
    *puVar3 = *(undefined1 *)(param_1 + 0x10);
    puVar3[1] = *(undefined1 *)(param_1 + 0x11);
    puVar3[2] = *(undefined1 *)(param_1 + 0x12);
    uVar4 = zb_put_next_htole16(puVar3 + 3,*(undefined2 *)(param_1 + 0x14));
    cVar1 = *(char *)(param_1 + 0x12);
    if (cVar1 == '\x01') {
      uVar4 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x16));
    }
    else if (cVar1 == '\x02') {
      uVar4 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x18));
    }
    else if (cVar1 == '\x03') {
      zb_put_next_htole16(*(undefined2 *)(param_1 + 0x16));
      uVar4 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x18));
    }
    zb_zcl_finish_and_send_packet
              (iVar2,uVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar6,0x201);
    zb_zcl_frame_get_sequence_number(iVar2);
  }
  return;
}

