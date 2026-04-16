/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_get_retry_params
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: dst_addr */
/* WARNING: Unknown calling convention */

void nwk_fwd_get_retry_params(zmsg_t *msg,uint8_t *retry_count,uint32_t *retry_delay)

{
  short sVar1;
  undefined4 uVar2;
  uint32_t uVar3;
  int iVar4;
  byte bStack_16;
  char cStack_15;
  ushort uStack_14;
  uint8_t rreq_cmd_opt;
  nwk_cmd_id_t cmd;
  ezb_shortaddr_t dst_addr;
  uint16_t fcf;
  
  cStack_15 = '\0';
  zmsg_read_bytes(0,2,&rreq_cmd_opt);
  zmsg_read_bytes(msg,2,&uStack_14);
  if ((_rreq_cmd_opt & 3) == 1) {
    uVar2 = zmsg_get_offset(msg);
    zmsg_read_bytes(msg,uVar2,1,&cStack_15);
  }
  if ((cStack_15 == '\b') || (cStack_15 == '\r')) {
    *retry_count = '\0';
    *retry_delay = 0;
  }
  else if (cStack_15 == '\x01') {
    sVar1 = zmsg_get_offset(msg);
    zmsg_read_bytes(msg,sVar1 + 1,1,&bStack_16);
    if ((bStack_16 & 0x18) == 0) {
      if ((msg->flags & 8) == 0) {
        *retry_count = '\x03';
        *retry_delay = 0xfe;
      }
      else {
        *retry_count = '\x02';
        uVar3 = random_add_jitter(0x7e);
        *retry_delay = uVar3;
      }
    }
    else {
      *retry_count = '\0';
      *retry_delay = 0;
    }
  }
  else if (uStack_14 < 0xfff8) {
    *retry_count = '\x03';
    *retry_delay = 0x32;
  }
  else {
    iVar4 = core_globals_get();
    *retry_count = *(uint8_t *)(iVar4 + 0x9d8);
    uVar3 = random_add_jitter(0,0x40);
    *retry_delay = uVar3;
  }
  return;
}

