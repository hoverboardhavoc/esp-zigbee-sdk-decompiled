/*
 * Last changed at upstream commit 503c5e49627f84174ce142bf784c3f01532fb5c9
 * https://github.com/espressif/esp-zigbee-sdk/commit/503c5e49627f84174ce142bf784c3f01532fb5c9
 * Upstream date: 2023-06-05 10:37:46 +0800
 * Upstream subject: esp-zigbee-sdk: optimize the zigbee cluster implementation(0f0acd4)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_config_report_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_config_report_cmd_req(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar2 = zb_buf_get_out_func();
  puVar3 = (undefined1 *)zb_buf_reuse_func();
  *puVar3 = 0;
  pcVar4 = (char *)zb_zcl_get_ctx();
  cVar1 = *pcVar4;
  *pcVar4 = cVar1 + '\x01';
  puVar3[1] = cVar1;
  puVar3[2] = 6;
  puVar3[3] = 0;
  puVar3 = (undefined1 *)zb_put_next_htole16(puVar3 + 4,*(undefined2 *)(param_1 + 0x12));
  *puVar3 = *(undefined1 *)(param_1 + 0x14);
  zb_put_next_htole16(puVar3 + 1,*(undefined2 *)(param_1 + 0x16));
  uVar5 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x18));
  iVar6 = zb_zcl_is_analog_data_type(*(undefined1 *)(param_1 + 0x14));
  if (iVar6 != 0) {
    uVar5 = zb_zcl_put_value_to_packet
                      (uVar5,*(undefined1 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x1c));
  }
  zb_zcl_finish_and_send_packet
            (uVar2,uVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x10));
  return;
}

