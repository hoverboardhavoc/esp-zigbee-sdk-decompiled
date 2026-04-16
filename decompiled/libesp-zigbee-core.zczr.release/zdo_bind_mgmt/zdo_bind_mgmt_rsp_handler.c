/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_bind_mgmt.o -> zdo_bind_mgmt_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_bind_mgmt_rsp_handler(void *arg)

{
  zdp_status_t zVar1;
  uint uVar2;
  zmsg_t *payload;
  uint8_t auStack_14 [2];
  uint16_t uStack_12;
  zdp_bind_rsp_field_t rsp;
  uint16_t offset;
  
  if (arg == (void *)0x0) {
    return 0x80;
  }
  zVar1 = 0x84;
  if (*(ushort *)((int)arg + 6) - 0x8021 < 2) {
    payload = *(zmsg_t **)((int)arg + 0x14);
    auStack_14[0] = '\0';
    if (payload != (zmsg_t *)0x0) {
      uStack_12 = 0;
      uVar2 = zmsg_get_length(payload);
      af_read_le8(payload,&uStack_12,auStack_14);
      if (uStack_12 <= uVar2) {
        zdo_packet_notify_result((int)arg + 8,0,auStack_14);
        return '\0';
      }
    }
    zVar1 = 0xfe;
  }
  return zVar1;
}

