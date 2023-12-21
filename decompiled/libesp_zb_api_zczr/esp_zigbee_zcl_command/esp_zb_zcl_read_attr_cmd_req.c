/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_read_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_read_attr_cmd_req(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  char *pcVar5;
  
  uVar3 = zb_buf_get_out_func();
  puVar4 = (undefined1 *)zb_buf_reuse_func();
  *puVar4 = 0;
  pcVar5 = (char *)zb_zcl_get_ctx();
  cVar1 = *pcVar5;
  *pcVar5 = cVar1 + '\x01';
  puVar4[1] = cVar1;
  puVar4[2] = 0;
  puVar4 = puVar4 + 3;
  iVar2 = 0;
  while ((iVar2 < (int)(uint)*(byte *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
    puVar4 = (undefined1 *)
             zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar2 * 2));
    iVar2 = iVar2 + 1;
  }
  zb_zcl_finish_and_send_packet
            (uVar3,puVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x10));
  zb_zcl_frame_get_sequence_number(uVar3);
  return;
}

