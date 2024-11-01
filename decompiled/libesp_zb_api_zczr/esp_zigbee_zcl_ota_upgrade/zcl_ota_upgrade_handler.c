/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_ota_upgrade.o -> zcl_ota_upgrade_handler
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
  uint *puVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  undefined4 uVar9;
  undefined1 uVar10;
  uint __n;
  uint uVar11;
  void *__src;
  uint uVar12;
  
  iVar6 = zb_buf_get_tail_func(0x38);
  iVar7 = esp_zb_has_core_action_handler();
  if (iVar7 == 0) {
_L0:
    uVar9 = 0xffffffff;
  }
  else {
    if (message_2 == (uint *)0x0) {
      message_2 = (uint *)malloc(0x30);
      if (message_2 == (uint *)0x0) {
        return 0xffffffea;
      }
      memset(message_2,0,0x30);
    }
    puVar4 = message_2;
    *message_2 = (uint)(iVar6 == 0);
    uVar10 = 0;
    if (iVar6 != 0) {
      uVar10 = *(undefined1 *)(iVar6 + 4);
    }
    *(undefined1 *)(puVar4 + 1) = uVar10;
    *(undefined2 *)((int)puVar4 + 6) = 0x19;
    bVar1 = *(byte *)(iVar6 + 0xc);
    *(undefined2 *)(puVar4 + 10) = 0;
    puVar4[2] = (uint)bVar1;
    puVar4[0xb] = 0;
    if (bVar1 == 2) {
      uVar11 = (uint)*(byte *)(iVar6 + 0x14);
      uVar12 = *(uint *)(iVar6 + 0x10);
      __src = *(void **)(iVar6 + 0x18);
      if (s_ota_header_1 == (void *)0x0) {
        s_ota_header_1 = malloc(0x45);
      }
      while (puVar4 = message_2, pvVar3 = s_ota_header_1, uVar11 != 0) {
        if (s_ota_header_length_0 <= uVar12) {
          *(short *)(message_2 + 10) = (short)uVar11;
          puVar4[0xb] = (uint)__src;
          iVar7 = esp_zb_core_action_handler_schedule(4);
          goto _L0;
        }
        __n = s_ota_header_length_0 - uVar12;
        if (uVar11 < __n) {
          __n = uVar11;
        }
        pvVar8 = (void *)((int)s_ota_header_1 + uVar12);
        uVar12 = uVar12 + __n;
        memcpy(pvVar8,__src,__n);
        puVar4 = message_2;
        uVar11 = uVar11 - __n & 0xff;
        __src = (void *)((int)__src + __n);
        if (0x37 < uVar12) {
          s_ota_header_length_0 = *(ushort *)((int)pvVar3 + 6);
        }
        if ((s_ota_header_length_0 <= uVar12) && (pvVar3 != (void *)0x0)) {
          pvVar8 = (void *)((int)message_2 + 0x1a);
          message_2[4] = *(uint *)((int)pvVar3 + 0xe);
          puVar4[5] = *(int *)((int)pvVar3 + 0x34) - (uint)*(ushort *)((int)pvVar3 + 6);
          *(undefined2 *)((int)puVar4 + 0xe) = *(undefined2 *)((int)pvVar3 + 0xc);
          uVar2 = *(ushort *)((int)pvVar3 + 8);
          *(ushort *)(puVar4 + 6) = uVar2;
          *(undefined2 *)(puVar4 + 3) = *(undefined2 *)((int)pvVar3 + 10);
          memset(pvVar8,0,0xe);
          if ((uVar2 & 1) == 0) {
            puVar5 = (undefined1 *)((int)pvVar3 + 0x38);
          }
          else {
            puVar5 = (undefined1 *)((int)pvVar3 + 0x39);
            *(undefined1 *)((int)puVar4 + 0x1a) = *(undefined1 *)((int)pvVar3 + 0x38);
          }
          if ((uVar2 & 2) != 0) {
            zb_memcpy8((int)puVar4 + 0x1b,puVar5);
            puVar5 = puVar5 + 8;
          }
          if ((puVar4[6] & 4) != 0) {
            *(undefined1 *)(puVar4 + 9) = *puVar5;
            *(undefined1 *)((int)puVar4 + 0x25) = puVar5[1];
            *(undefined1 *)((int)puVar4 + 0x26) = puVar5[2];
            *(undefined1 *)((int)puVar4 + 0x27) = puVar5[3];
          }
        }
      }
    }
    else {
      iVar7 = esp_zb_core_action_handler_schedule(4);
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
        if (iVar7 == 0x105) {
          uVar10 = 10;
        }
        else if (iVar7 == 0x10c) {
          uVar10 = 9;
        }
        else {
          uVar10 = 7;
        }
        *(undefined1 *)(iVar6 + 0xc) = uVar10;
        goto _L0;
      }
    }
    *(undefined1 *)(iVar6 + 0xc) = 6;
    uVar9 = 0;
  }
  return uVar9;
}

