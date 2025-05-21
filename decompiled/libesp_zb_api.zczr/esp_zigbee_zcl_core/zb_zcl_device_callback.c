/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_core.o -> zb_zcl_device_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_device_callback(undefined4 param_1)

{
  short sVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  short *psVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  code *pcVar13;
  short *psVar14;
  undefined4 uStack_34;
  undefined1 uStack_30;
  short sStack_2e;
  short sStack_2c;
  ushort uStack_2a;
  undefined2 uStack_28;
  ushort uStack_26;
  int iStack_24;
  
  piVar3 = (int *)zb_buf_get_tail_func(0x38);
  for (piVar11 = (int *)s_device_cb_list; piVar11 + -2 != (int *)0xfffffff8;
      piVar11 = (int *)*piVar11) {
    if ((piVar11[-2] == *piVar3) && (pcVar13 = (code *)piVar11[-1], pcVar13 != (code *)0x0)) {
      iVar4 = zb_buf_get_tail_func(param_1,0x38);
      uVar7 = (*pcVar13)(param_1);
      goto _L0;
    }
  }
  if (*piVar3 == 0) {
    iVar4 = zb_buf_get_tail_func(param_1,0x38);
    iVar5 = zb_buf_get_tail_func(param_1,0x38);
    sVar1 = *(short *)(iVar5 + 0xc);
    uStack_30 = *(undefined1 *)(iVar5 + 4);
    sVar2 = *(short *)(iVar5 + 0xe);
    uStack_34 = 0;
    uStack_2a = 0;
    uStack_28 = 0;
    uStack_26 = 0;
    iStack_24 = 0;
    sStack_2e = sVar1;
    sStack_2c = sVar2;
    iVar6 = zb_af_get_endpoint_desc();
    uVar7 = 0xffffffe4;
    if (iVar6 != 0) {
      for (iVar9 = 0; iVar9 < (int)(uint)*(byte *)(iVar6 + 0x10); iVar9 = iVar9 + 1) {
        psVar8 = (short *)(*(int *)(iVar6 + 0x11) + iVar9 * 0xf);
        if (sVar1 == *psVar8) {
          iVar6 = 0;
          goto _L0;
        }
      }
_L0:
      uVar7 = 0xffffffe4;
    }
_L0:
    *(undefined4 *)(iVar4 + 8) = uVar7;
  }
  else if ((zcl_device_id_cb == (code *)0x0) || (iVar4 = (*zcl_device_id_cb)(param_1), iVar4 == 0))
  {
    iVar4 = zb_buf_get_tail_func(param_1,0x38);
    *(undefined4 *)(iVar4 + 8) = 0xffffffff;
  }
  return;
_L0:
  if ((int)(uint)(ushort)psVar8[1] <= iVar6) goto _L0;
  psVar14 = (short *)(*(int *)(psVar8 + 2) + iVar6 * 10);
  if (sVar2 == *psVar14) {
    uVar12 = (uint)*(byte *)(psVar14 + 1);
    uStack_28 = 0;
    uStack_2a = (ushort)*(byte *)(psVar14 + 1);
    if (uVar12 == 0x25) {
_L0:
      uStack_26 = 6;
_L0:
      iStack_24 = iVar5 + 0x10;
    }
    else {
      if (0x25 < uVar12) {
        if (uVar12 < 0x52) {
          if (0x38 < uVar12) {
            uVar10 = 1 << (uVar12 - 0x39 & 0x1f);
            if ((uVar10 & 0x1888f00) == 0) {
              if (uVar12 == 0x3a) goto _L0;
              if ((uVar10 & 1) == 0) goto _L0;
              goto _L0;
            }
_L0:
            uStack_26 = (ushort)*(byte *)(iVar5 + 0x10);
            iStack_24 = *(int *)(iVar5 + 0x14);
            goto _L0;
          }
          if (uVar12 == 0x2d) goto _L0;
          if (uVar12 < 0x2e) {
            if (uVar12 == 0x2a) goto _L0;
            if (uVar12 < 0x2b) {
              if (uVar12 != 0x28) {
                uVar10 = 0x29;
                goto _L122;
              }
              goto _L0;
            }
            uVar10 = 0x2b;
            goto _L116;
          }
          if ((uVar12 != 0x31) && (uVar12 != 0x38)) {
            uVar10 = 0x30;
_L114:
            if (uVar12 == uVar10) goto _L0;
            goto _L0;
          }
_L0:
          uStack_26 = 2;
        }
        else {
          if (uVar12 != 0xf0) {
            if (uVar12 < 0xf1) {
              if (0xe9 < uVar12) {
                uVar10 = 0xea;
                goto _L116;
              }
              if (0xe7 < uVar12) goto _L0;
              if ((uVar12 + 0x20 & 0xff) < 3) goto _L0;
            }
            else if (uVar12 == 0xf1) goto _L0;
            goto _L0;
          }
_L0:
          uStack_26 = 8;
        }
        goto _L0;
      }
      if (uVar12 == 0xd) goto _L0;
      if (uVar12 < 0xe) {
        if (uVar12 == 0) {
          uStack_26 = 0;
          iStack_24 = 0;
          goto _L0;
        }
        if (uVar12 == 10) goto _L0;
        if (uVar12 < 0xb) {
          if (uVar12 != 8) {
            uVar10 = 9;
_L122:
            if (uVar12 == uVar10) goto _L0;
            goto _L0;
          }
_L0:
          uStack_26 = 1;
          goto _L0;
        }
        uVar10 = 0xb;
      }
      else {
        if (uVar12 == 0x1d) goto _L0;
        if (uVar12 < 0x1e) {
          if (uVar12 == 0x19) goto _L0;
          if (uVar12 < 0x1a) {
            uVar12 = uVar12 & 0xf7;
            uVar10 = 0x10;
            goto _L114;
          }
          if (uVar12 == 0x1a) goto _L0;
          uVar10 = 0x1b;
        }
        else {
          if (uVar12 == 0x22) {
_L0:
            uStack_26 = 3;
            goto _L0;
          }
          if (uVar12 < 0x23) {
            if (uVar12 != 0x20) {
              uVar10 = 0x21;
              goto _L122;
            }
            goto _L0;
          }
          uVar10 = 0x23;
        }
      }
_L116:
      if (uVar12 == uVar10) {
_L0:
        uStack_26 = 4;
        goto _L0;
      }
_L0:
      uStack_34 = 1;
      uVar7 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ZCL_CORE",&_LC1,uVar7,"ESP_ZIGBEE_ZCL_CORE",(char)psVar14[1]);
    }
_L0:
    uVar7 = 0;
    if (zb_core_action_cb != (code *)0x0) {
      (*zb_core_action_cb)(&uStack_34);
      uVar7 = esp_err_to_zb_ret();
    }
    goto _L0;
  }
  iVar6 = iVar6 + 1;
  goto _L0;
}

