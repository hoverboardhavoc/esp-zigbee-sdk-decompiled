/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
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
  int iVar5;
  int iVar6;
  
  uVar2 = zb_buf_get_out_func();
  if (**(int **)(param_1 + 0x14) == 0) {
    puVar3 = (undefined1 *)zb_buf_reuse_func();
    *puVar3 = 0;
    pcVar4 = (char *)zb_zcl_get_ctx();
    cVar1 = *pcVar4;
    *pcVar4 = cVar1 + '\x01';
    puVar3[1] = cVar1;
    puVar3[2] = 6;
  }
  else {
    puVar3 = (undefined1 *)zb_buf_reuse_func();
    *puVar3 = 8;
    pcVar4 = (char *)zb_zcl_get_ctx();
    cVar1 = *pcVar4;
    *pcVar4 = cVar1 + '\x01';
    puVar3[1] = cVar1;
    puVar3[2] = 6;
  }
  puVar3 = puVar3 + 3;
  iVar6 = 0;
  while ((iVar6 < (int)(uint)*(ushort *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
    *puVar3 = 0;
    puVar3 = (undefined1 *)
             zb_put_next_htole16(puVar3 + 1,*(undefined2 *)(*(int *)(param_1 + 0x14) + 4));
    *puVar3 = *(undefined1 *)(*(int *)(param_1 + 0x14) + 6);
    zb_put_next_htole16(puVar3 + 1,*(undefined2 *)(*(int *)(param_1 + 0x14) + 8));
    puVar3 = (undefined1 *)zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + 10));
    iVar5 = zb_zcl_is_analog_data_type(*(undefined1 *)(*(int *)(param_1 + 0x14) + 6));
    if (iVar5 != 0) {
      puVar3 = (undefined1 *)
               zb_zcl_put_value_to_packet
                         (puVar3,*(undefined1 *)(*(int *)(param_1 + 0x14) + 6),
                          *(undefined4 *)(*(int *)(param_1 + 0x14) + 0xc));
    }
    iVar6 = iVar6 + 1;
  }
  zb_zcl_finish_and_send_packet
            (uVar2,puVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x10));
  zb_zcl_frame_get_sequence_number(uVar2);
  return;
}

