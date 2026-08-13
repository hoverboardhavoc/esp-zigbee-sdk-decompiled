/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_general_cmd_handler(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x49a,
                  "zcl_general_cmd_handler","packet");
_L0:
    if (param_2 == 1) {
      iVar1 = zcl_general_read_attr_rsp_handler(param_1,&uStack_38);
    }
    else if (param_2 == 2) {
      iVar1 = zcl_general_write_attr_handler(param_1,&uStack_38);
    }
    else {
      if (param_2 != 0) {
        iVar1 = 0x81;
        goto _L0;
      }
      iVar1 = zcl_general_read_attr_handler(param_1,&uStack_38);
    }
  }
  else {
    iVar1 = zcl_packet_init(&uStack_38,*(byte *)(param_1 + 0x1a) >> 2 & 1);
    if (iVar1 != 0) goto _L0;
    param_2 = (uint)*(byte *)(param_1 + 0x20);
    if (param_2 == 9) {
      iVar1 = zcl_general_read_reporting_configuration_rsp_handler(param_1,&uStack_38);
    }
    else if (param_2 < 10) {
      if (param_2 == 4) {
        iVar1 = zcl_general_write_attr_rsp_handler(param_1,&uStack_38);
      }
      else {
        if (param_2 < 5) goto _L0;
        if (param_2 == 7) {
          iVar1 = zcl_general_configure_reporting_rsp_handler(param_1,&uStack_38);
        }
        else if (param_2 == 8) {
          iVar1 = zcl_cmd_read_reporting_configuration_handler(param_1,&uStack_38);
        }
        else {
          if (param_2 != 6) {
            iVar1 = 0x81;
            goto _L0;
          }
          iVar1 = zcl_cmd_configure_reporting_handler(param_1,&uStack_38);
        }
      }
    }
    else if (param_2 == 0xd) {
      iVar1 = zcl_general_disc_attr_rsp_handler(param_1,&uStack_38);
    }
    else if (param_2 < 0xe) {
      if (param_2 == 0xb) {
        iVar1 = zcl_general_default_rsp_handler(param_1,&uStack_38);
      }
      else if (param_2 == 0xc) {
        iVar1 = zcl_general_disc_attr_handler(param_1,&uStack_38);
      }
      else {
        if (param_2 != 10) {
          iVar1 = 0x81;
          goto _L0;
        }
        iVar1 = zcl_general_report_attr_handler(param_1,&uStack_38);
      }
    }
    else if (param_2 == 0x13) {
_L0:
      iVar1 = zcl_general_disc_cmd_handler(param_1,&uStack_38);
    }
    else {
      if (param_2 < 0x14) {
        if (param_2 == 0x11) goto _L0;
        if (param_2 != 0x12) {
          iVar1 = 0x81;
          goto _L0;
        }
      }
      else if (param_2 != 0x14) {
        iVar1 = 0x81;
        goto _L0;
      }
      iVar1 = zcl_general_disc_cmd_rsp_handler(param_1,&uStack_38);
    }
  }
  if (iVar1 == 0) {
    zcl_packet_send(&uStack_38,0);
    return 0;
  }
_L0:
  zcl_packet_free(&uStack_38);
  return iVar1;
}

