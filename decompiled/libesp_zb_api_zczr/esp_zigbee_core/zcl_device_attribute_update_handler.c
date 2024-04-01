/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_device_attribute_update_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_device_attribute_update_handler(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  undefined4 uVar7;
  byte *pbVar8;
  uint uVar9;
  char *pcVar10;
  uint uVar11;
  short *psVar12;
  int iVar13;
  undefined4 uStack_34;
  char cStack_30;
  short sStack_2e;
  short sStack_2c;
  ushort uStack_2a;
  undefined2 uStack_28;
  ushort uStack_26;
  int iStack_24;
  
  iVar4 = zb_buf_get_tail_func(0x38);
  cVar1 = *(char *)(iVar4 + 4);
  sVar2 = *(short *)(iVar4 + 0xc);
  sVar3 = *(short *)(iVar4 + 0xe);
  uStack_34 = 0;
  uStack_2a = 0;
  uStack_28 = 0;
  uStack_26 = 0;
  iStack_24 = 0;
  cStack_30 = cVar1;
  sStack_2e = sVar2;
  sStack_2c = sVar3;
  iVar5 = zb_zcl_get_ctx();
  iVar13 = 0;
  if (*(int *)(iVar5 + 8) != 0) goto _L0;
  do {
    if (iVar13 != 0) {
      return -0x1c;
    }
    iVar5 = zb_zcl_get_ctx();
    iVar13 = 1;
    if (*(int *)(iVar5 + 0xc) == 0) {
      return -0x1c;
    }
_L0:
    iVar5 = zb_zcl_get_ctx();
    pbVar8 = *(byte **)(iVar5 + iVar13 * 4 + 8);
    for (iVar5 = 0; iVar5 < (int)(uint)*pbVar8; iVar5 = iVar5 + 1) {
      pcVar10 = *(char **)(*(int *)(pbVar8 + 1) + iVar5 * 4);
      if (*pcVar10 == cVar1) {
        iVar5 = 0;
        while( true ) {
          if ((int)(uint)(byte)pcVar10[0x10] <= iVar5) {
            return -0x1c;
          }
          psVar6 = (short *)(*(int *)(pcVar10 + 0x11) + iVar5 * 0xf);
          if (sVar2 == *psVar6) break;
          iVar5 = iVar5 + 1;
        }
        iVar5 = 0;
        while( true ) {
          if ((int)(uint)(ushort)psVar6[1] <= iVar5) {
            return -0x1c;
          }
          psVar12 = (short *)(*(int *)(psVar6 + 2) + iVar5 * 10);
          if (sVar3 == *psVar12) break;
          iVar5 = iVar5 + 1;
        }
        uVar11 = (uint)*(byte *)(psVar12 + 1);
        uStack_28 = 0;
        uStack_2a = (ushort)*(byte *)(psVar12 + 1);
        if (uVar11 == 0x25) goto _L0;
        if (0x25 < uVar11) {
          if (uVar11 < 0x52) {
            if (0x38 < uVar11) {
              uVar9 = 1 << (uVar11 - 0x39 & 0x1f);
              if ((uVar9 & 0x1888f00) != 0) {
_L0:
                uStack_26 = (ushort)*(byte *)(iVar4 + 0x10);
                iStack_24 = *(int *)(iVar4 + 0x14);
                goto _L0;
              }
              if (uVar11 == 0x3a) goto _L0;
              if ((uVar9 & 1) == 0) goto _L0;
_L0:
              uStack_26 = 4;
              goto _L0;
            }
            if (uVar11 == 0x2d) goto _L0;
            if (uVar11 < 0x2e) {
              if (uVar11 == 0x2a) goto _L0;
              if (uVar11 < 0x2b) {
                if (uVar11 != 0x28) {
                  uVar9 = 0x29;
                  goto _L866;
                }
                goto _L0;
              }
              uVar9 = 0x2b;
              goto _L860;
            }
            if ((uVar11 == 0x31) || (uVar11 == 0x38)) {
_L0:
              uStack_26 = 2;
              goto _L0;
            }
            uVar9 = 0x30;
_L858:
            if (uVar11 == uVar9) goto _L0;
          }
          else {
            if (uVar11 == 0xf0) {
_L0:
              uStack_26 = 8;
              goto _L0;
            }
            if (uVar11 < 0xf1) {
              if (0xe9 < uVar11) {
                uVar9 = 0xea;
                goto _L860;
              }
              if (0xe7 < uVar11) goto _L0;
              if ((uVar11 + 0x20 & 0xff) < 3) goto _L0;
            }
            else if (uVar11 == 0xf1) goto _L0;
          }
_L0:
          uStack_34 = 1;
          uVar7 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC15,uVar7,"ESP_ZIGBEE_CORE",(char)psVar12[1]);
          goto _L0;
        }
        if (uVar11 == 0xd) {
_L0:
          uStack_26 = 6;
        }
        else {
          if (0xd < uVar11) {
            if (uVar11 != 0x1d) {
              if (uVar11 < 0x1e) {
                if (uVar11 == 0x19) goto _L0;
                if (uVar11 < 0x1a) {
                  uVar11 = uVar11 & 0xf7;
                  uVar9 = 0x10;
                  goto _L858;
                }
                if (uVar11 == 0x1a) goto _L0;
                uVar9 = 0x1b;
              }
              else {
                if (uVar11 == 0x22) {
_L0:
                  uStack_26 = 3;
                  goto _L0;
                }
                if (uVar11 < 0x23) {
                  if (uVar11 != 0x20) {
                    uVar9 = 0x21;
                    goto _L866;
                  }
                  goto _L0;
                }
                uVar9 = 0x23;
              }
_L860:
              if (uVar11 == uVar9) goto _L0;
              goto _L0;
            }
            goto _L0;
          }
          if (uVar11 == 0) {
            uStack_26 = 0;
            iStack_24 = 0;
            goto _L0;
          }
          if (uVar11 == 10) goto _L0;
          uVar9 = 0xb;
          if (10 < uVar11) goto _L860;
          if (uVar11 != 8) {
            uVar9 = 9;
_L866:
            if (uVar11 == uVar9) goto _L0;
            goto _L0;
          }
_L0:
          uStack_26 = 1;
        }
_L0:
        iStack_24 = iVar4 + 0x10;
_L0:
        if (zb_core_action_cb == (code *)0x0) {
          return 0;
        }
        iVar4 = (*zb_core_action_cb)(0,&uStack_34);
        if (iVar4 == 0x105) {
          iVar5 = -0x1c;
        }
        else if (iVar4 < 0x106) {
          iVar5 = -0x16;
          if ((iVar4 != 0x101) && (iVar5 = -6, iVar4 != 0x104)) {
            return -(uint)(iVar4 != 0);
          }
        }
        else {
          iVar5 = -0x1e;
          if ((iVar4 != 0x107) && (iVar5 = -2, iVar4 != 0x10c)) {
            return -1;
          }
        }
        return iVar5;
      }
    }
  } while( true );
}

