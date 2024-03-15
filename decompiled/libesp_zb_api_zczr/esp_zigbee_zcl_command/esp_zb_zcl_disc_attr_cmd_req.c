/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_disc_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_disc_attr_cmd_req(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC10,uVar5,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_disc_attr_cmd_req",0x168);
    pcVar4 = (char *)zb_zcl_get_ctx();
    *pcVar4 = *pcVar4 + '\x01';
  }
  else {
    puVar3 = (undefined1 *)zb_buf_reuse_func();
    if (*(int *)(param_1 + 0x18) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
    *puVar3 = uVar6;
    pcVar4 = (char *)zb_zcl_get_ctx();
    cVar1 = *pcVar4;
    *pcVar4 = cVar1 + '\x01';
    puVar3[1] = cVar1;
    puVar3[2] = 0xc;
    puVar3 = (undefined1 *)zb_put_next_htole16(puVar3 + 3,*(undefined2 *)(param_1 + 0x12));
    *puVar3 = *(undefined1 *)(param_1 + 0x14);
    zb_zcl_finish_and_send_packet
              (iVar2,puVar3 + 1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x10));
    zb_zcl_frame_get_sequence_number(iVar2);
  }
  return;
}

