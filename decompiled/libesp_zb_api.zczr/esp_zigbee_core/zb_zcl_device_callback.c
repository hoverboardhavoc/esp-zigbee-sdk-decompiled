/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> zb_zcl_device_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_device_callback(undefined4 param_1)

{
  char cVar1;
  short sVar2;
  short sVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  short *psVar9;
  byte *pbVar10;
  uint uVar11;
  int *piVar12;
  char *pcVar13;
  uint uVar14;
  code *pcVar15;
  short *psVar16;
  int iVar17;
  undefined4 uStack_34;
  char cStack_30;
  short sStack_2e;
  short sStack_2c;
  ushort uStack_2a;
  undefined2 uStack_28;
  ushort uStack_26;
  int iStack_24;
  
  piVar4 = (int *)zb_buf_get_tail_func(0x38);
  for (piVar12 = (int *)s_device_cb_list; piVar12 + -2 != (int *)0xfffffff8;
      piVar12 = (int *)*piVar12) {
    if ((piVar12[-2] == *piVar4) && (pcVar15 = (code *)piVar12[-1], pcVar15 != (code *)0x0)) {
      iVar5 = zb_buf_get_tail_func(param_1,0x38);
      uVar8 = (*pcVar15)(param_1);
      goto _L0;
    }
  }
  if (*piVar4 == 0) {
    iVar5 = zb_buf_get_tail_func(param_1,0x38);
    iVar6 = zb_buf_get_tail_func(param_1,0x38);
    cVar1 = *(char *)(iVar6 + 4);
    sVar2 = *(short *)(iVar6 + 0xc);
    sVar3 = *(short *)(iVar6 + 0xe);
    uStack_34 = 0;
    uStack_2a = 0;
    uStack_28 = 0;
    uStack_26 = 0;
    iStack_24 = 0;
    iVar17 = 0;
    cStack_30 = cVar1;
    sStack_2e = sVar2;
    sStack_2c = sVar3;
    while( true ) {
      iVar7 = zb_zcl_get_ctx();
      if (*(int *)(iVar7 + iVar17 * 4 + 8) != 0) {
        iVar7 = zb_zcl_get_ctx();
        pbVar10 = *(byte **)(iVar7 + iVar17 * 4 + 8);
        for (iVar7 = 0; iVar7 < (int)(uint)*pbVar10; iVar7 = iVar7 + 1) {
          pcVar13 = *(char **)(*(int *)(pbVar10 + 1) + iVar7 * 4);
          if (*pcVar13 == cVar1) {
            iVar17 = 0;
            goto _L0;
          }
        }
      }
      if (iVar17 != 0) break;
      iVar17 = 1;
    }
_L0:
    uVar8 = 0xffffffe4;
_L0:
    *(undefined4 *)(iVar5 + 8) = uVar8;
  }
  else if ((zcl_device_id_cb == (code *)0x0) || (iVar5 = (*zcl_device_id_cb)(param_1), iVar5 == 0))
  {
    iVar5 = zb_buf_get_tail_func(param_1,0x38);
    *(undefined4 *)(iVar5 + 8) = 0xffffffff;
  }
  return;
_L0:
  if ((int)(uint)(byte)pcVar13[0x10] <= iVar17) goto _L0;
  psVar9 = (short *)(*(int *)(pcVar13 + 0x11) + iVar17 * 0xf);
  if (sVar2 == *psVar9) {
    iVar17 = 0;
    goto _L0;
  }
  iVar17 = iVar17 + 1;
  goto _L0;
_L0:
  if ((int)(uint)(ushort)psVar9[1] <= iVar17) goto _L0;
  psVar16 = (short *)(*(int *)(psVar9 + 2) + iVar17 * 10);
  if (sVar3 == *psVar16) {
    uVar14 = (uint)*(byte *)(psVar16 + 1);
    uStack_28 = 0;
    uStack_2a = (ushort)*(byte *)(psVar16 + 1);
    if (uVar14 == 0x25) {
_L0:
      uStack_26 = 6;
_L0:
      iStack_24 = iVar6 + 0x10;
    }
    else {
      if (0x25 < uVar14) {
        if (uVar14 < 0x52) {
          if (0x38 < uVar14) {
            uVar11 = 1 << (uVar14 - 0x39 & 0x1f);
            if ((uVar11 & 0x1888f00) == 0) {
              if (uVar14 == 0x3a) goto _L0;
              if ((uVar11 & 1) == 0) goto _L0;
              goto _L0;
            }
_L0:
            uStack_26 = (ushort)*(byte *)(iVar6 + 0x10);
            iStack_24 = *(int *)(iVar6 + 0x14);
            goto _L0;
          }
          if (uVar14 == 0x2d) goto _L0;
          if (uVar14 < 0x2e) {
            if (uVar14 == 0x2a) goto _L0;
            if (uVar14 < 0x2b) {
              if (uVar14 != 0x28) {
                uVar11 = 0x29;
                goto _L136;
              }
              goto _L0;
            }
            uVar11 = 0x2b;
            goto _L130;
          }
          if ((uVar14 != 0x31) && (uVar14 != 0x38)) {
            uVar11 = 0x30;
_L128:
            if (uVar14 == uVar11) goto _L0;
            goto _L0;
          }
_L0:
          uStack_26 = 2;
        }
        else {
          if (uVar14 != 0xf0) {
            if (uVar14 < 0xf1) {
              if (0xe9 < uVar14) {
                uVar11 = 0xea;
                goto _L130;
              }
              if (0xe7 < uVar14) goto _L0;
              if ((uVar14 + 0x20 & 0xff) < 3) goto _L0;
            }
            else if (uVar14 == 0xf1) goto _L0;
            goto _L0;
          }
_L0:
          uStack_26 = 8;
        }
        goto _L0;
      }
      if (uVar14 == 0xd) goto _L0;
      if (uVar14 < 0xe) {
        if (uVar14 == 0) {
          uStack_26 = 0;
          iStack_24 = 0;
          goto _L0;
        }
        if (uVar14 == 10) goto _L0;
        if (uVar14 < 0xb) {
          if (uVar14 != 8) {
            uVar11 = 9;
_L136:
            if (uVar14 == uVar11) goto _L0;
            goto _L0;
          }
_L0:
          uStack_26 = 1;
          goto _L0;
        }
        uVar11 = 0xb;
      }
      else {
        if (uVar14 == 0x1d) goto _L0;
        if (uVar14 < 0x1e) {
          if (uVar14 == 0x19) goto _L0;
          if (uVar14 < 0x1a) {
            uVar14 = uVar14 & 0xf7;
            uVar11 = 0x10;
            goto _L128;
          }
          if (uVar14 == 0x1a) goto _L0;
          uVar11 = 0x1b;
        }
        else {
          if (uVar14 == 0x22) {
_L0:
            uStack_26 = 3;
            goto _L0;
          }
          if (uVar14 < 0x23) {
            if (uVar14 != 0x20) {
              uVar11 = 0x21;
              goto _L136;
            }
            goto _L0;
          }
          uVar11 = 0x23;
        }
      }
_L130:
      if (uVar14 == uVar11) {
_L0:
        uStack_26 = 4;
        goto _L0;
      }
_L0:
      uStack_34 = 1;
      uVar8 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC2,uVar8,"ESP_ZIGBEE_CORE",(char)psVar16[1]);
    }
_L0:
    uVar8 = 0;
    if (zb_core_action_cb != (code *)0x0) {
      (*zb_core_action_cb)(&uStack_34);
      uVar8 = esp_err_to_zb_ret();
    }
    goto _L0;
  }
  iVar17 = iVar17 + 1;
  goto _L0;
}

