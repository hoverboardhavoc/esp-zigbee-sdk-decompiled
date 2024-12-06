/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_ota_upgrade.o -> zcl_ota_upgrade_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ota_upgrade_handler(void)

{
  void *pvVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  uint uVar9;
  uint uVar10;
  void *__src;
  
  iVar5 = zb_buf_get_tail_func(0x38);
  iVar6 = esp_zb_has_core_action_handler();
  if (iVar6 == 0) {
    uVar7 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar7,0x10000,"zcl_ota_upgrade_handler",0x5c);
    return 0xffffffff;
  }
  if (message_2 == (uint *)0x0) {
    message_2 = (uint *)malloc(0x30);
    if (message_2 == (uint *)0x0) {
      uVar7 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC3,uVar7,0x10000,"zcl_ota_upgrade_handler",0x5f);
      return 0xffffffea;
    }
    memset(message_2,0,0x30);
  }
  puVar2 = message_2;
  *message_2 = (uint)(iVar5 == 0);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = *(undefined1 *)(iVar5 + 4);
  }
  *(undefined1 *)(puVar2 + 1) = uVar8;
  *(undefined2 *)((int)puVar2 + 6) = 0x19;
  puVar2[2] = (uint)*(byte *)(iVar5 + 0xc);
  *(undefined2 *)(puVar2 + 10) = 0;
  puVar2[0xb] = 0;
  if (*(char *)(iVar5 + 0xc) == '\x02') {
    uVar10 = (uint)*(byte *)(iVar5 + 0x14);
    uVar4 = *(uint *)(iVar5 + 0x10);
    __src = *(void **)(iVar5 + 0x18);
    if (s_ota_header_1 == (void *)0x0) {
      s_ota_header_1 = malloc(0x45);
    }
    while ((puVar2 = message_2, pvVar1 = s_ota_header_1, uVar10 != 0 &&
           (uVar4 < s_ota_header_length_0))) {
      uVar9 = s_ota_header_length_0 - uVar4;
      uVar3 = uVar10;
      if (uVar9 < uVar10) {
        uVar3 = uVar9;
      }
      uVar9 = uVar3 & 0xff;
      memcpy((void *)((int)s_ota_header_1 + uVar4),__src,uVar9);
      uVar10 = uVar10 - (uVar3 & 0xff) & 0xff;
      uVar4 = uVar4 + uVar9;
      __src = (void *)((int)__src + uVar9);
      if (0x37 < uVar4) {
        s_ota_header_length_0 = *(ushort *)((int)pvVar1 + 6);
      }
      if (s_ota_header_length_0 <= uVar4) {
        zb_populate_ota_file_header(message_2 + 3,pvVar1);
      }
    }
    if (uVar10 == 0) goto _L0;
    *(short *)(message_2 + 10) = (short)uVar10;
    puVar2[0xb] = (uint)__src;
    iVar6 = esp_zb_core_action_handler_schedule(4);
  }
  else {
    iVar6 = esp_zb_core_action_handler_schedule(4);
    if ((byte)(*(char *)(iVar5 + 0xc) - 3U) < 2) {
      s_ota_header_length_0 = 0x38;
      if (s_ota_header_1 != (void *)0x0) {
        free(s_ota_header_1);
        s_ota_header_1 = (void *)0x0;
      }
      if (message_2 != (uint *)0x0) {
        free(message_2);
        message_2 = (uint *)0x0;
      }
    }
  }
  if (iVar6 != 0) {
    if (iVar6 == 0x10c) {
      *(undefined1 *)(iVar5 + 0xc) = 8;
      return 0;
    }
    if (iVar6 != 0x103) {
      *(undefined1 *)(iVar5 + 0xc) = 7;
      return 0;
    }
    *(undefined1 *)(iVar5 + 0xc) = 9;
    return 0;
  }
_L0:
  *(undefined1 *)(iVar5 + 0xc) = 6;
  return 0;
}

