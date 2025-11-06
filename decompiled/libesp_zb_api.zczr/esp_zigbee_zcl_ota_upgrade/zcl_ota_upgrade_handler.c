/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_ota_upgrade.o -> zcl_ota_upgrade_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ota_upgrade_handler(void)

{
  byte bVar1;
  ushort uVar2;
  void *pvVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  void *pvVar9;
  undefined1 uVar10;
  uint uVar11;
  void *__src;
  uint __n;
  uint uVar12;
  
  iVar6 = zb_buf_get_tail_func(0x38);
  iVar7 = esp_zb_has_core_action_handler();
  if (iVar7 == 0) {
    return 0xffffffff;
  }
  puVar8 = message_2;
  if (message_2 == (uint *)0x0) {
    puVar8 = (uint *)malloc(0x30);
    if (puVar8 == (uint *)0x0) {
      message_2 = puVar8;
      return 0xffffffea;
    }
    message_2 = puVar8;
    memset(puVar8,0,0x30);
  }
  *puVar8 = (uint)(iVar6 == 0);
  uVar10 = 0;
  if (iVar6 != 0) {
    uVar10 = *(undefined1 *)(iVar6 + 4);
  }
  *(undefined1 *)(puVar8 + 1) = uVar10;
  *(undefined2 *)((int)puVar8 + 6) = 0x19;
  bVar1 = *(byte *)(iVar6 + 0xc);
  *(undefined2 *)(puVar8 + 10) = 0;
  puVar8[2] = (uint)bVar1;
  puVar8[0xb] = 0;
  if (bVar1 == 2) {
    uVar11 = (uint)*(byte *)(iVar6 + 0x14);
    uVar12 = *(uint *)(iVar6 + 0x10);
    __src = *(void **)(iVar6 + 0x18);
    if (s_ota_header_1 == (void *)0x0) {
      s_ota_header_1 = malloc(0x45);
    }
    while (puVar8 = message_2, pvVar3 = s_ota_header_1, uVar11 != 0) {
      uVar5 = (uint)s_ota_header_length_0;
      if (uVar5 <= uVar12) {
        *(short *)(message_2 + 10) = (short)uVar11;
        puVar8[0xb] = (uint)__src;
        iVar7 = esp_zb_core_action_handler_schedule(4);
        goto _L0;
      }
      __n = uVar5 - uVar12;
      if (uVar11 < uVar5 - uVar12) {
        __n = uVar11;
      }
      pvVar9 = (void *)((int)s_ota_header_1 + uVar12);
      uVar12 = uVar12 + __n;
      memcpy(pvVar9,__src,__n);
      puVar8 = message_2;
      uVar11 = uVar11 - __n & 0xff;
      __src = (void *)((int)__src + __n);
      if (0x37 < uVar12) {
        s_ota_header_length_0 = *(ushort *)((int)pvVar3 + 6);
        uVar5 = (uint)s_ota_header_length_0;
      }
      if ((uVar5 <= uVar12) && (pvVar3 != (void *)0x0)) {
        pvVar9 = (void *)((int)message_2 + 0x1a);
        message_2[4] = *(uint *)((int)pvVar3 + 0xe);
        puVar8[5] = *(int *)((int)pvVar3 + 0x34) - (uint)*(ushort *)((int)pvVar3 + 6);
        *(undefined2 *)((int)puVar8 + 0xe) = *(undefined2 *)((int)pvVar3 + 0xc);
        uVar2 = *(ushort *)((int)pvVar3 + 8);
        *(ushort *)(puVar8 + 6) = uVar2;
        *(undefined2 *)(puVar8 + 3) = *(undefined2 *)((int)pvVar3 + 10);
        memset(pvVar9,0,0xe);
        if ((uVar2 & 1) == 0) {
          puVar4 = (undefined1 *)((int)pvVar3 + 0x38);
        }
        else {
          puVar4 = (undefined1 *)((int)pvVar3 + 0x39);
          *(undefined1 *)((int)puVar8 + 0x1a) = *(undefined1 *)((int)pvVar3 + 0x38);
        }
        if ((uVar2 & 2) != 0) {
          zb_memcpy8((int)puVar8 + 0x1b,puVar4);
          puVar4 = puVar4 + 8;
        }
        if ((puVar8[6] & 4) != 0) {
          *(undefined1 *)(puVar8 + 9) = *puVar4;
          *(undefined1 *)((int)puVar8 + 0x25) = puVar4[1];
          *(undefined1 *)((int)puVar8 + 0x26) = puVar4[2];
          *(undefined1 *)((int)puVar8 + 0x27) = puVar4[3];
        }
      }
    }
  }
  else {
    iVar7 = esp_zb_core_action_handler_schedule(4,puVar8);
    if ((byte)(*(char *)(iVar6 + 0xc) - 3U) < 2) {
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
_L0:
    if (iVar7 != 0) {
      uVar10 = 8;
      if ((iVar7 != 0x10c) && (uVar10 = 7, iVar7 == 0x103)) {
        uVar10 = 9;
      }
      goto _L0;
    }
  }
  uVar10 = 6;
_L0:
  *(undefined1 *)(iVar6 + 0xc) = uVar10;
  return 0;
}

