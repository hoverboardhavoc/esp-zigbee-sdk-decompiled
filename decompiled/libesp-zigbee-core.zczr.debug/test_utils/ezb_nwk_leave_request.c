/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> test_utils.o -> ezb_nwk_leave_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_nwk_leave_request(ezb_nwk_leave_req_t *req)

{
  ezb_err_t eVar1;
  uint8_t uStack_1c;
  uint8_t uStack_1b;
  uint8_t uStack_1a;
  uint8_t uStack_19;
  nwk_leave_req_t nwk_req;
  
  uStack_1c = (req->device_address).field_0.u8[0];
  uStack_1b = (req->device_address).field_0.u8[1];
  uStack_1a = (req->device_address).field_0.u8[2];
  uStack_19 = (req->device_address).field_0.u8[3];
  nwk_req.device_address.field_0.u8[0] = (req->device_address).field_0.u8[4];
  nwk_req.device_address.field_0.u8[1] = (req->device_address).field_0.u8[5];
  nwk_req.device_address.field_0.u8[2] = (req->device_address).field_0.u8[6];
  nwk_req.device_address.field_0.u8[3] = (req->device_address).field_0.u8[7];
  nwk_req.device_address.field_0.u8[4] =
       (byte)(((byte)req->field_0x8 >> 1 & 1) << 1) |
       nwk_req.device_address.field_0.u8[4] & 0xfc | req->field_0x8 & 1;
  eVar1 = nwk_leave_request(&uStack_1c);
  return eVar1;
}

