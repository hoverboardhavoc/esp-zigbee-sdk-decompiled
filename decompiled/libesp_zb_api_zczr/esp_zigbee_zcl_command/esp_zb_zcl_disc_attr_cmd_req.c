/*
 * Last changed at upstream commit 6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * https://github.com/espressif/esp-zigbee-sdk/commit/6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * Upstream date: 2023-09-18 10:30:22 +0800
 * Upstream subject: esp-zigbee-sdk: add zigbee trace support and assert support(8c01f3c7)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_disc_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_disc_attr_cmd_req(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  
  uVar2 = zb_buf_get_out_func();
  puVar3 = (undefined1 *)zb_buf_reuse_func();
  if (*(int *)(param_1 + 0x18) == 0) goto _L0;
  uVar6 = 8;
  do {
    *puVar3 = uVar6;
    pcVar4 = (char *)zb_zcl_get_ctx();
    cVar1 = *pcVar4;
    *pcVar4 = cVar1 + '\x01';
    puVar3[1] = cVar1;
    puVar3[2] = 0xc;
    puVar5 = (undefined1 *)zb_put_next_htole16(puVar3 + 3,*(undefined2 *)(param_1 + 0x12));
    *puVar5 = *(undefined1 *)(param_1 + 0x14);
    zb_zcl_finish_and_send_packet
              (uVar2,puVar5 + 1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x10));
    zb_assert("/home/xiaqilin/esp/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zcl_command.c",0xf0
             );
_L0:
    uVar6 = 0;
  } while( true );
}

