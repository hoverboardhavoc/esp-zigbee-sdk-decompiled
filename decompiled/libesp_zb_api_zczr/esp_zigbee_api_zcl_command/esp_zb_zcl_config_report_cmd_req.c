/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_zcl_command.o -> esp_zb_zcl_config_report_cmd_req
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
  zb_put_next_htole16(puVar3 + 1,*(undefined1 *)(param_1 + 0x15));
  uVar5 = zb_put_next_htole16(*(undefined1 *)(param_1 + 0x16));
  iVar6 = zb_zcl_is_analog_data_type(*(undefined1 *)(param_1 + 0x14));
  if (iVar6 != 0) {
    uVar5 = zb_zcl_put_value_to_packet(uVar5,*(undefined1 *)(param_1 + 0x14),param_1 + 0x18);
  }
  zb_zcl_finish_and_send_packet
            (uVar2,uVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x10));
  return;
}

