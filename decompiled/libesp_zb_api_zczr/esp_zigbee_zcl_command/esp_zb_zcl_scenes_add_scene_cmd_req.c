/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_scenes_add_scene_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_add_scene_cmd_req(int param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = zb_buf_get_out_func();
  zb_zcl_start_command_header(1,0,0,0);
  puVar2 = (undefined1 *)zb_put_next_htole16(*(undefined2 *)(param_1 + 10));
  *puVar2 = *(undefined1 *)(param_1 + 0xc);
  puVar2 = (undefined1 *)zb_put_next_htole16(puVar2 + 1,*(undefined2 *)(param_1 + 0xe));
  *puVar2 = 0;
  puVar2 = puVar2 + 1;
  while (*(undefined2 **)(param_1 + 0x10) != (undefined2 *)0x0) {
    puVar2 = (undefined1 *)zb_put_next_htole16(**(undefined2 **)(param_1 + 0x10));
    *puVar2 = *(undefined1 *)(*(int *)(param_1 + 0x10) + 2);
    uVar4 = 0;
    while( true ) {
      puVar2 = puVar2 + 1;
      iVar3 = *(int *)(param_1 + 0x10);
      if (*(byte *)(iVar3 + 2) <= uVar4) break;
      *puVar2 = *(undefined1 *)(*(int *)(iVar3 + 4) + uVar4);
      uVar4 = uVar4 + 1 & 0xff;
    }
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar3 + 8);
  }
  zb_zcl_finish_and_send_packet
            (uVar1,puVar2,param_1,2,*(undefined1 *)(param_1 + 8),*(undefined1 *)(param_1 + 9),0x104,
             5);
  zb_zcl_frame_get_sequence_number(uVar1);
  return;
}

