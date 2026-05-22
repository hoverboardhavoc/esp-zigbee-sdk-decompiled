/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_general_cmd_handler(zcl_packet_t *packet)

{
  zcl_status_t zVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined3 extraout_var_09;
  undefined3 extraout_var_10;
  undefined3 extraout_var_11;
  undefined3 extraout_var_12;
  uint in_a5;
  undefined1 auStack_38 [4];
  zcl_packet_t rsp;
  
  auStack_38 = (undefined1  [4])0x0;
  rsp.header.src_addr._0_4_ = 0;
  rsp.header.src_addr.u._2_4_ = 0;
  rsp.header._8_4_ = 0;
  rsp.header.dst_addr.u._0_2_ = 0;
  rsp.header.dst_addr.u._2_2_ = 0;
  rsp.header.dst_addr.u._4_4_ = 0;
  rsp.header.src_ep = '\0';
  rsp.header.dst_ep = '\0';
  rsp.header.cluster_id = 0;
  rsp.header.profile_id = 0;
  rsp.header.fc = '\0';
  rsp.header._27_1_ = 0;
  rsp.header.manuf_code = 0;
  rsp.header.tsn = '\0';
  rsp.header.rssi = '\0';
  rsp.header.cmd_id = '\0';
  rsp.header._33_1_ = 0;
  rsp._34_2_ = 0;
  if (packet == (zcl_packet_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x47c,
                  "zcl_general_cmd_handler","packet");
_L0:
    if (in_a5 == 1) {
      zVar1 = zcl_general_read_attr_rsp_handler(packet,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_03,zVar1);
    }
    else if (in_a5 == 2) {
      zVar1 = zcl_general_write_attr_handler(packet,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_04,zVar1);
    }
    else {
      if (in_a5 != 0) {
        iVar2 = 0x81;
        goto _L0;
      }
      zVar1 = zcl_general_read_attr_handler(packet,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_00,zVar1);
    }
    goto _L0;
  }
  iVar2 = zcl_packet_init(auStack_38,(packet->header).fc >> 2 & 1);
  if (iVar2 != 0) goto _L0;
  in_a5 = (uint)(packet->header).cmd_id;
  if (in_a5 == 9) {
    zVar1 = zcl_general_read_reporting_configuration_rsp_handler(packet,(zcl_packet_t *)auStack_38);
    iVar2 = CONCAT31(extraout_var_08,zVar1);
_L0:
    if (iVar2 == 0) {
      zcl_packet_send(auStack_38,0);
      goto _L0;
    }
  }
  else {
    if (in_a5 < 10) {
      if (in_a5 == 4) {
        zVar1 = zcl_general_write_attr_rsp_handler(packet,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_05,zVar1);
      }
      else {
        if (in_a5 < 5) goto _L0;
        if (in_a5 == 7) {
          zVar1 = zcl_general_configure_reporting_rsp_handler(packet,(zcl_packet_t *)auStack_38);
          iVar2 = CONCAT31(extraout_var_06,zVar1);
        }
        else if (in_a5 == 8) {
          zVar1 = zcl_cmd_read_reporting_configuration_handler(packet,(zcl_packet_t *)auStack_38);
          iVar2 = CONCAT31(extraout_var_07,zVar1);
        }
        else {
          if (in_a5 != 6) {
            iVar2 = 0x81;
            goto _L0;
          }
          zVar1 = zcl_cmd_configure_reporting_handler(packet,(zcl_packet_t *)auStack_38);
          iVar2 = CONCAT31(extraout_var,zVar1);
        }
      }
      goto _L0;
    }
    if (in_a5 == 0xd) {
      zVar1 = zcl_general_disc_attr_rsp_handler(packet,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_10,zVar1);
      goto _L0;
    }
    if (in_a5 < 0xe) {
      if (in_a5 == 0xb) {
        zVar1 = zcl_general_default_rsp_handler(packet,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_12,zVar1);
      }
      else if (in_a5 == 0xc) {
        zVar1 = zcl_general_disc_attr_handler(packet,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_09,zVar1);
      }
      else {
        if (in_a5 != 10) {
          iVar2 = 0x81;
          goto _L0;
        }
        zVar1 = zcl_general_report_attr_handler(packet,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_01,zVar1);
      }
      goto _L0;
    }
    if (in_a5 == 0x13) {
_L0:
      zVar1 = zcl_general_disc_cmd_handler(packet,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_11,zVar1);
      goto _L0;
    }
    if (in_a5 < 0x14) {
      if (in_a5 == 0x11) goto _L0;
      if (in_a5 == 0x12) goto _L0;
      iVar2 = 0x81;
    }
    else {
      if (in_a5 == 0x14) {
_L0:
        zVar1 = zcl_general_disc_cmd_rsp_handler(packet,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_02,zVar1);
        goto _L0;
      }
      iVar2 = 0x81;
    }
  }
_L0:
  zcl_packet_free(auStack_38);
_L0:
  return (zcl_status_t)iVar2;
}

