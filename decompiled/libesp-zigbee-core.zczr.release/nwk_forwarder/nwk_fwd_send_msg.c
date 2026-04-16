/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_send_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_send_msg(zmsg_t *msg)

{
  int iVar1;
  ushort uStack_14;
  ushort uStack_12;
  uint16_t fcf;
  
  zmsg_read_le16(msg,0,&uStack_14);
  iVar1 = nwk_is_device_zczr();
  if (iVar1 == 0) {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xa28) != '\0') {
      uStack_14 = uStack_14 | 0x2000;
    }
  }
  else {
    uStack_14 = uStack_14 & 0xdfff;
  }
  uStack_12 = uStack_14;
  zmsg_write_bytes(msg,0,2,&uStack_12);
  msg->nwk_retries = '\0';
  nwk_fwd_do_send_msg(msg);
  return;
}

