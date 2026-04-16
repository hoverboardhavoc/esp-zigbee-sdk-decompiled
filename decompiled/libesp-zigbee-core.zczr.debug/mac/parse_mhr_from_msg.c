/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> parse_mhr_from_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t parse_mhr_from_msg(zmsg_t *msg,mac_header_t *mhr,uint8_t *mhr_len)

{
  undefined1 uVar1;
  ezb_err_t eVar2;
  undefined4 *puStack_48;
  ezb_radio_frame_t frame;
  undefined4 uStack_2c;
  uint8_t buf [26];
  
  uStack_2c = 0;
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  buf[9] = '\0';
  buf[10] = '\0';
  buf[0xb] = '\0';
  buf[0xc] = '\0';
  buf[0xd] = '\0';
  buf[0xe] = '\0';
  buf[0xf] = '\0';
  buf[0x10] = '\0';
  buf[0x11] = '\0';
  buf[0x12] = '\0';
  buf[0x13] = '\0';
  buf[0x14] = '\0';
  buf[0x15] = '\0';
  frame.psdu = (uint8_t *)0x0;
  frame.length = '\0';
  frame.channel = '\0';
  frame._6_2_ = 0;
  frame.info.tx.timestamp._0_4_ = 0;
  frame.info.tx.timestamp._4_4_ = 0;
  frame.info._8_4_ = 0;
  puStack_48 = &uStack_2c;
  uVar1 = zmsg_read_bytes(0,0x1a);
  frame.psdu = (uint8_t *)CONCAT31(frame.psdu._1_3_,uVar1);
  eVar2 = mac_frame_parse_header(&puStack_48,mhr,mhr_len);
  return eVar2;
}

